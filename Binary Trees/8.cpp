// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

vector <int> bottomView(Node *root) 
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            mp[p.second]=p.first->data;
            if(p.first->left)
            q.push({p.first->left,p.second-1});
            if(p.first->right)
            q.push({p.first->right,p.second+1});
        }
        for(auto p:mp)
        ans.push_back(p.second);
        return ans;
    }
