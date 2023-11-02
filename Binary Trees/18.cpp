// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
            q.push({node->left,{x-1,y+1}});
            if(node->right)
            q.push({node->right,{x+1,y+1}});
        }
        for(auto p:nodes)
        {
            vector<int> col;
            for(auto s:p.second)
            col.insert(col.end(),s.second.begin(),s.second.end());
            ans.push_back(col);
        }
        return ans;
    }
