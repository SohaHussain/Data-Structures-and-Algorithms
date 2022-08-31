//

// modified preorder traversal (root->right->left)
void solve(TreeNode *node, vector<int> &ans,int level)
    {
        if(node==NULL)        
            return;
        if(level==ans.size())
            ans.push_back(node->val);
        solve(node->right,ans,level+1);
        solve(node->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        if(root==NULL)
            return ans;
        solve(root,ans,0);
        return ans;
    }
