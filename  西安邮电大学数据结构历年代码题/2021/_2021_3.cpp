#include <iostream>

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 辅助函数，用于中序遍历并检查节点值是否有序递增
bool helper(TreeNode* root, TreeNode*& prev) {
    if (root == NULL) {
        return true;
    }
    // 递归遍历左子树
    if (!helper(root->left, prev)) {
        return false;
    }
    // 检查当前节点值是否大于中序遍历的前一个节点值
    if (prev!= NULL && root->val <= prev->val) {
        return false;
    }
    prev = root;
    // 递归遍历右子树
    return helper(root->right, prev);
}

// 主函数，判断二叉树是否为二叉排序树
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
        std::cout << "该二叉树是二叉排序树" << std::endl;
    } else {
        std::cout << "该二叉树不是二叉排序树" << std::endl;
    }
    return 0;
}