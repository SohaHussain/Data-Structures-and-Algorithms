// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

vector<int> topView(Node *root)
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
        if(mp.find(p.second)==mp.end())
            mp.insert({p.second,p.first->data});
        if(p.first->left)
            q.push({p.first->left,p.second-1});
        if(p.first->right)
            q.push({p.first->right,p.second+1});
        }
        for(auto p:mp)
        {
        ans.push_back(p.second);
        }
    return ans;
}
