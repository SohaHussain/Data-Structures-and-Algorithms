// TC : O(sqrt(n))
// SC : O(n)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> fact;
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if((n/i)==i)
            fact.push_back(i);
            else
            {
                fact.push_back(i);
                fact.push_back(n/i);
            }
        }
    }
    sort(fact.begin(),fact.end());
    for(auto i:fact)
    cout<<i<<" ";
    return 0;
}
