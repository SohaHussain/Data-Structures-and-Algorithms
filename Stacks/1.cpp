 vector<long long> nextLargerElement(vector<long long> arr, int n)
 {
        vector<long long> ans;
        stack<long long> st;
        int i=n-1;
        while(i>=0)
        {
            if(st.empty())
            {
                st.push(arr[i]);
                ans.push_back(-1);
                i--;
            }
            else if(!st.empty() && st.top()>arr[i])
            {
                ans.push_back(st.top());
                st.push(arr[i]);
                i--;
            }
            else if(!st.empty() && st.top()<=arr[i])
            {
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
