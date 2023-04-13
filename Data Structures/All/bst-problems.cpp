vector<int>vv;
void inorder(TreeNode*root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    vv.push_back(root->val);
    inorder(root->right);
}
bool isValidBST(TreeNode* root) {
    if(root == NULL)
        return 1;
    inorder(root);
    int n = vv.size();
    for(int i=1;i<n;i++)
    {
        if(vv[i] <= vv[i-1])
            return false;
    }
    return true;
}
