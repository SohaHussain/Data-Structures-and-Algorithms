// https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1/#

typedef long long ll;
    ll ele(ll a[],ll n,ll k)
    {
        priority_queue<ll> maxh;
        for(ll i=0;i<n;i++)
        {
            maxh.push(a[i]);
            if(maxh.size()>k)
            maxh.pop();
        }
        return maxh.top();
    }
    ll sumBetweenTwoKth( ll A[], ll N, ll K1, ll K2)
    {
        ll f = ele(A,N,K1);
        ll s = ele(A,N,K2);
        ll ans = 0;
        for(ll i=0;i<N;i++)
        {
            if(A[i]>f && A[i]<s)
            ans+=A[i];
        }
        return ans;
    }
