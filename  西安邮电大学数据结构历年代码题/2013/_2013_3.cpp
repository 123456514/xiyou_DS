// 计算二叉树的单个孩子的节点数
//int get_node_count_one(treenode *root){
//    if(root == NULL) return 0;
//    if((root->right!=NULL && root->left==NULL) || (root->right==NULL && root->left!=NULL)) return count+=1;
//    get_node_count_one(root->left);
//    get_node_count_one(root->right);
//    return 0;
//}