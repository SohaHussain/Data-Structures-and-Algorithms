// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1/#

vector<int> leftSmaller(int n, int arr[]){
        vector<int> ans;
        stack<int> st;
        int i=0;
        while(i<n)
        {
            if(st.empty())
            {
                ans.push_back(-1);
                st.push(arr[i]);
                i++;
            }
            else if(st.top()<arr[i])
            {
                ans.push_back(st.top());
                st.push(arr[i]);
                i++;
            }
            else if(st.top()>=arr[i])
            {
                st.pop();
            }
        }
        return ans;
    }
