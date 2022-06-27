// https://leetcode.com/problems/palindrome-partitioning/

// make the next recursion call only if substring from (index -> i) is a palindrome.
// base condition is when the partition reaches the end of the string meaning all valid partitions for the strings have been performed and the resultant substrings
// is a valid ans.

bool palcheck(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
    
    void solve(int ind, string s, vector<vector<string>>&ans, vector<string>&ds)
    {
        if(ind == s.length())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.length();i++)
        {
            if(palcheck(s,ind,i))
            {
                ds.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s,ans,ds);
        return ans;
    }
