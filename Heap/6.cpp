// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

typedef long long ll;
   
    ll minCost(ll arr[], ll n) {
        ll ans=0;
        priority_queue<ll,vector<ll>,greater<ll>> minh;
        for(ll i=0;i<n;i++)
        {
            minh.push(arr[i]);
        }
        while(minh.size()>1)
        {
            ll a = minh.top();
           
            minh.pop();
            ll b = minh.top();
            
            minh.pop();
            ans=ans+(a+b);
            
            minh.push(a+b);
        }
        
        return ans;
    }
