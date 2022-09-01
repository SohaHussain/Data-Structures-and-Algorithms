// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
         if(root==NULL || root==p || root==q)  // if anyone node is found or null return that node 
             return root;
        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);
        if(l==NULL) // if left is null return right value
            return r;
        else if(r==NULL) // if right is null return left value
            return l;
        else
            return root; // ans found if neither right or left is null
    }
