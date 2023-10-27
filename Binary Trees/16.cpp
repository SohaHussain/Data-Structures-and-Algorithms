// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rev=false;
        while(!q.empty())
        {
            int s=q.size();
            vector<int> level(s);
            for(int i=0;i<s;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int idx=(rev)? s-i-1: i;
                level[idx]=node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            rev=!rev;
            ans.push_back(level);
        }
        return ans;
    }
