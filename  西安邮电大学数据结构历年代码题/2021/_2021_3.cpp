#include <iostream>

// ����������ڵ�ṹ��
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ��������������������������ڵ�ֵ�Ƿ��������
bool helper(TreeNode* root, TreeNode*& prev) {
    if (root == NULL) {
        return true;
    }
    // �ݹ����������
    if (!helper(root->left, prev)) {
        return false;
    }
    // ��鵱ǰ�ڵ�ֵ�Ƿ�������������ǰһ���ڵ�ֵ
    if (prev!= NULL && root->val <= prev->val) {
        return false;
    }
    prev = root;
    // �ݹ����������
    return helper(root->right, prev);
}

// ���������ж϶������Ƿ�Ϊ����������
bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return helper(root, prev);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    if (isValidBST(root)) {
        std::cout << "�ö������Ƕ���������" << std::endl;
    } else {
        std::cout << "�ö��������Ƕ���������" << std::endl;
    }
    return 0;
}