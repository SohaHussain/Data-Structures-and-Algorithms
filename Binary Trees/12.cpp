// https://practice.geeksforgeeks.org/problems/burning-tree/1

    Node* markpar(Node* node, map<Node*,Node*> &mp,int target)
    {
        queue<Node*> q;
        q.push(node);
        Node* res;
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            if(curr->data==target)
            res=curr;
            if(curr->left)
            {
                q.push(curr->left);
                mp[curr->left]=curr;
            }
            if(curr->right)
            {
                q.push(curr->right);
                mp[curr->right]=curr;
            }
        }
        return res;
    }
    
    int solve(map<Node*,Node*> &mp, Node* target)
    {
        queue<Node*> q;
        q.push(target);
        map<Node*,int> vis;
        vis[target]=1;
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            int flag=0;
            for(int i=0;i<s;i++)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=1;
                    flag=1;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=1;
                    flag=1;
                }
                if(mp[curr] && !vis[mp[curr]])
                {
                    q.push(mp[curr]);
                    vis[mp[curr]]=1;
                    flag=1;
                }
            }
            if(flag==1)
            ans++;
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> parents;
        Node* start = markpar(root,parents,target);
        int ans=solve(parents,start);
        return ans;
    }
};

