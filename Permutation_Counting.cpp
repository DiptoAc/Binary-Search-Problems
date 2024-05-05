#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =3e5+1;
ll n,m;
bool prd(vector<ll>&v,ll x,ll ele)
{
    ll i;
    for(i=0;i<n;i++)
    {
        if(v[i]<x)
        {
            ele-=(x-v[i]);
        }
        if(ele<0){return false;}
    }
    return true;
}
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        vector<ll>v(n);
        for(auto &it:v){cin>>it;}
        ll mx=0,o=1;
        for(i=50;i>=0;i--)
        {
            if(prd(v,mx+(o<<i),k))
            {
                mx+=(o<<i);
            }
        }
        for(i=0;i<n;i++)
        {
            if(v[i]<mx)
            {
                k-=mx-v[i];
                v[i]=mx;
            }
        }
        ll cnt=0;
        for(i=0;i<n;i++)
        {
            if(v[i]==mx)
            {
                if(k){v[i]++;k--;}
                else{cnt++;}
            }
        }
        cout<<(n*mx-cnt+1)<<endl;
    }
}
