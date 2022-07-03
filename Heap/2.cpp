vector <int> nearlySorted(int arr[], int num, int k){
        priority_queue<int,vector<int>,greater<int>> minh;
        vector<int> ans;
        for(int i=0;i<num;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>k)
            {
                ans.push_back(minh.top());
                minh.pop();
            }
        }
        while(minh.size())
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }