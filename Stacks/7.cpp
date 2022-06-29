// https://leetcode.com/problems/maximal-rectangle/

// MAH starts (maximum area histogram)
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
    
    int mah(vector<int>& heights) {
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
    // MAH ends

// new concept -> converting 2d binary array to 1d heights array for MAH
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans =INT_MIN;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>h;
        for(int i=0;i<c;i++)
        {
            if(matrix[0][i]=='1')
                h.insert(h.begin()+i,1);
            else
                h.insert(h.begin()+i,0);
        }
        ans = max(ans,mah(h));
        int currrow = 1;
        while(currrow < r)
        {
            for(int i=0;i<c;i++)
            {
                if(matrix[currrow][i]=='1')
                    h[i] = h[i]+1;
                else
                    h[i]=0;
            }
            ans = max(ans,mah(h));
            currrow++;
        }
        return ans;
    }
