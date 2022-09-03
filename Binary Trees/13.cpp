// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

TreeNode *solve(vector<int> &pre,int prestart,int preend,vector<int> &in,int instart,int inend,unordered_map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)
            return NULL;
        TreeNode *root= new TreeNode(pre[prestart]);
        int ele=mp[root->val];
        int n=ele-instart;
        root->left=solve(pre,prestart+1,prestart+n,in,instart,ele-1,mp);
        root->right=solve(pre,prestart+n+1,preend,in,ele+1,inend,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int prestart=0;
        int preend=preorder.size()-1;
        int instart=0;
        int inend=inorder.size()-1;
        unordered_map<int,int>mp;
        // enter all elements in inorder into a hashmap to find their position in constant time
        for(int i=instart;i<=inend;i++) 
            mp[inorder[i]]=i;
        return solve(preorder,prestart,preend,inorder,instart,inend,mp);
    }
