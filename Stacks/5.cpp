// https://www.geeksforgeeks.org/the-stock-span-problem/

void solve(vector<int> &arr,vector<int> &ans,int n)
{
    int i=0;
  // pair {index,element}
    stack<pair<int,int>> st;
  // vector to store the index of the nearest greater element to the left in the array
    vector<int> ind;
    while(i<n)
    {
        if(st.empty())
        {
            ind.push_back(-1);
            st.push({i,arr[i]});
            i++;
        }
        else if(st.top().second>arr[i])
        {
            ind.push_back(st.top().first);
            st.push({i,arr[i]});
            i++;
        }
        else if(st.top().second<=arr[i])
        {
            st.pop();
        }
    }
    for(int i=0;i<n;i++)
    ans.push_back(i-ind[i]);
}
