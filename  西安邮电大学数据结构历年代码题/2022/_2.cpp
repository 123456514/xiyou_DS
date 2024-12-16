// ��д�㷨��ʵ�����ַ�����ʽ����ļ򵥱��ʽ��ֵ�����ʽ�����������+-*/%���֣�������֪���� float getValue(char ch[],int start)
// �ܷ����ַ�����startλ�ÿ��Եĵ�һ�����֡�
// ������ ch="1.2+3.4*5.6+7.8",��getValue(ch,1),���ص�ֵ��1.2��getValue(ch,5),���ص�ֵ��3.4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �ܷ����ַ�����startλ�ÿ�ʼ�ĵ�һ������
float getValue(char ch[], int start) {
    int len = strlen(ch);
    int i = start;
    int dot_count = 0;  // ���ڼ�¼С������ֵĴ���
    int sign = 1;  // ���ڼ�¼���ֵķ��ţ�1��ʾ����-1��ʾ��
    float num = 0;  // ���ڴ洢���ս�������������
    float decimal = 1;  // ���ڴ���С�����֣���ʼ��Ϊ1����������С������λ�����е���

    // ����ǰ��Ŀհ��ַ�������У�
    while (i < len && isspace(ch[i])) {
        i++;
    }

    // �ж�������
    if (i < len && (ch[i] == '+' || ch[i] == '-')) {
        sign = (ch[i++] == '+')? 1 : -1;
    }

    // ������������
    while (i < len && isdigit(ch[i])) {
        num = num * 10 + (ch[i++] - '0');
    }

    // ����С������
    if (i < len && ch[i] == '.') {
        i++;
        dot_count++;
        while (i < len && isdigit(ch[i])) {
            num = num * 10 + (ch[i++] - '0');
            decimal *= 10;
        }
    }

    // ���С������ִ����Ƿ�Ϸ�
    if (dot_count > 1) {
        printf("�Ƿ������ָ�ʽ\n");
        exit(1);
    }

    return num * sign / decimal;
}

// ִ��������������
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
                printf("��������Ϊ0\n");
                exit(1);
            }
            return num1 / num2;
        case '%':
            if ((int)num2 == 0) {
                printf("ȡ�������������Ϊ0\n");
                exit(1);
            }
            return (int)num1 % (int)num2;
        default:
            printf("��֧�ֵ������\n");
            exit(1);
    }
}

// ������ʽ��ֵ
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
    printf("��������ʽ��");
    scanf("%s", expression);
    float value = evaluateExpression(expression);
    printf("���ʽ��ֵΪ��%f\n", value);
    return 0;
}