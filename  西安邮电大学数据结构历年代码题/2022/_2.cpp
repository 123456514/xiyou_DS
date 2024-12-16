// 编写算法，实现以字符串形式输入的简单表达式求值，表达式的运算符仅有+-*/%五种，并且已知函数 float getValue(char ch[],int start)
// 能返回字符串从start位置考试的第一个数字。
// ；例如 ch="1.2+3.4*5.6+7.8",则getValue(ch,1),返回的值是1.2，getValue(ch,5),返回的值是3.4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 能返回字符串从start位置开始的第一个数字
float getValue(char ch[], int start) {
    int len = strlen(ch);
    int i = start;
    int dot_count = 0;  // 用于记录小数点出现的次数
    int sign = 1;  // 用于记录数字的符号，1表示正，-1表示负
    float num = 0;  // 用于存储最终解析出来的数字
    float decimal = 1;  // 用于处理小数部分，初始化为1，后续根据小数点后的位数进行调整

    // 跳过前面的空白字符（如果有）
    while (i < len && isspace(ch[i])) {
        i++;
    }

    // 判断正负号
    if (i < len && (ch[i] == '+' || ch[i] == '-')) {
        sign = (ch[i++] == '+')? 1 : -1;
    }

    // 解析整数部分
    while (i < len && isdigit(ch[i])) {
        num = num * 10 + (ch[i++] - '0');
    }

    // 解析小数部分
    if (i < len && ch[i] == '.') {
        i++;
        dot_count++;
        while (i < len && isdigit(ch[i])) {
            num = num * 10 + (ch[i++] - '0');
            decimal *= 10;
        }
    }

    // 检查小数点出现次数是否合法
    if (dot_count > 1) {
        printf("非法的数字格式\n");
        exit(1);
    }

    return num * sign / decimal;
}

// 执行两个数的运算
float calculate(float num1, char op, float num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("除数不能为0\n");
                exit(1);
            }
            return num1 / num2;
        case '%':
            if ((int)num2 == 0) {
                printf("取余运算除数不能为0\n");
                exit(1);
            }
            return (int)num1 % (int)num2;
        default:
            printf("不支持的运算符\n");
            exit(1);
    }
}

// 计算表达式的值
// 1.2+3.4*5.6+7.8
float evaluateExpression(char ch[]) {
    int len = strlen(ch);
    float result = getValue(ch, 0);
    float num;
    char op;
    for (int i = 0; i < len; i++) {
        if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%') {
            op = ch[i];
            num = getValue(ch, i + 1);
            result = calculate(result, op, num);
        }
    }
    return result;
}

int main() {
    char expression[100];
    printf("请输入表达式：");
    scanf("%s", expression);
    float value = evaluateExpression(expression);
    printf("表达式的值为：%f\n", value);
    return 0;
}