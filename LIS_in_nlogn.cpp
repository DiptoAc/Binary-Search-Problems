#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =2e2+5;
ll n,m;
vector<ll>takingTheElementOfThisPosition;
//This code computes LIS in nlogn time complexity and n space complexity.
ll longest_increasing_subsequence(vector<ll> &v)
{
    if(v.empty()){return 0;}
    vector<ll>track;
    track.pb(v[0]);
    takingTheElementOfThisPosition[0]=1;
    for(int i=1;i<v.size();i++)
    {
        if(track.back()<v[i])
        {
            track.pb(v[i]);
            takingTheElementOfThisPosition[i]=track.size();
            continue;
        }
        ll pos= lower_bound(track.begin(),track.end(),v[i])-track.begin();
        track[pos]=v[i];
        takingTheElementOfThisPosition[i]=pos+1;
    }
    //Returns the length of longest increasing subsequence.
    return track.size();
}
int32_t main()
{
    fast
    ll i,j,k,p,q,tc=1,cs=0;cin>>tc;
    while(tc--)
    {
        cin>>n;
        takingTheElementOfThisPosition.resize(n,0);
        vector<ll>v(n);
        for(auto &it:v){cin>>it;}
        cout<<longest_increasing_subsequence(v)<<endl;
        for(auto it:takingTheElementOfThisPosition){cout<<it<<" ";}cout<<endl;
    }
}

