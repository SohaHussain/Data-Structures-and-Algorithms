// https://leetcode.com/problems/largest-rectangle-in-histogram/

void leftindx(vector<int>& arr,vector<int> &v)
    {
        stack<pair<int,int>> st;
        int i=0;
        while(i<arr.size())
        {
            if(st.empty())
            {
                v.push_back(-1);
                st.push({i,arr[i]});
                i++;
            }
            else if(st.top().second < arr[i])
            {
                v.push_back(st.top().first);
                st.push({i,arr[i]});
                i++;
            }
            else if(st.top().second >= arr[i])
            {
                st.pop();
            }
        }
        
    }
    
    void rightindx(vector<int>& arr,vector<int> &v)
    {
        stack<pair<int,int>> st;
        int i=arr.size()-1;
        while(i>=0)
        {
            if(st.empty())
            {
                v.push_back(arr.size());
                st.push({i,arr[i]});
                i--;
            }
            else if(st.top().second < arr[i])
            {
                v.push_back(st.top().first);
                st.push({i,arr[i]});
                i--;
            }
            else if(st.top().second >= arr[i])
            {
                st.pop();
            }
        }
        reverse(v.begin(),v.end());
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nsl;
        vector<int>nsr;
        leftindx(heights,nsl);
        rightindx(heights,nsr);
        int ans = INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            ans = max(ans,heights[i]*(nsr[i]-nsl[i]-1));
        }
        return ans;
    }
