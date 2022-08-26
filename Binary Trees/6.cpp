// https://leetcode.com/problems/balanced-binary-tree/

 bool isBalanced(TreeNode* root) 
    {
        return dfs(root)!=-1;
    }
    int dfs(TreeNode *node)
    {
        if(node==NULL)
            return 0;
        int l=dfs(node->left);
        if(l==-1)
            return -1;
        int r=dfs(node->right);
        if(r==-1)
            return -1;
        if(abs(r-l)>1)
            return -1;
        return max(l,r)+1;        
    }