// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

TreeNode *solve(vector<int> &in,int instart,int inend,vector<int> &post,int poststart,int postend,unordered_map<int,int> &mp)
    {
        if(poststart>postend || instart>inend)
            return NULL;
        TreeNode *root=new TreeNode(post[postend]);
        int ind=mp[post[postend]];
        TreeNode *l=solve(in,instart,ind-1,post,poststart,poststart+ind-instart-1,mp);
        TreeNode *r=solve(in,ind+1,inend,post,poststart+ind-instart,postend-1,mp);
        root->left=l;
        root->right=r;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
