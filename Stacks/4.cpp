// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/

vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int> ans;
        stack<int> st;
        int i=n-1;
        while(i>=0)
        {
            if(st.empty())
            {
                ans.push_back(-1);
                st.push(arr[i]);
                i--;
            }
            else if(st.top()<arr[i])
            {
                ans.push_back(st.top());
                st.push(arr[i]);
                i--;
            }
            else if(st.top()>=arr[i])
            {
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    } 
