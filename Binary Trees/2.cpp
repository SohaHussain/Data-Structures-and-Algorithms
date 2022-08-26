// https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void solve(TreeNode *node, vector<int> &ans)
    {
        if(node==NULL)
            return;
        solve(node->left,ans);
        ans.push_back(node->val);
        solve(node->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }