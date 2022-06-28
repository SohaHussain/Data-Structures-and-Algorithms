// https://www.geeksforgeeks.org/previous-greater-element/

void solve(vector<int> &arr,int n,vector<int> &ans)
{
    stack<int>st;
    int i=0;
    while(i<n)
    {
        if(st.empty())
        {
            ans.push_back(-1);
            st.push(arr[i]);
            i++;
        }
        else if(!st.empty() && st.top()>arr[i])
        {
            ans.push_back(st.top());
            st.push(arr[i]);
            i++;
        }
        else if(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
    }
}
