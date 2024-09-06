#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
#define LLONG_MAX 1e16
const ll M =1e9+7;
const ll N =3e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
vector<vector<ll>>jump(40,vector<ll>(N,-1));
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n>>q;
        for(i=1;i<=n;i++)
        {
            cin>>k;
            jump[0][i]=k;
        }
        for(i=1;i<=33;i++)
        {
            for(j=1;j<=n;j++){jump[i][j]=jump[i-1][jump[i-1][j]];}
        }
        while(q--)
        {
            ll x,y;
            cin>>x>>y;
            for(i=32;i>=0;i--){if((1<<i)&y){x=jump[i][x];}}
            cout<<x<<endl;
        }
    }
}
//https://cses.fi/problemset/task/1750

//এটা একটা ক্ল্যাসিক প্রবলেম। বাইনারি লিফটিং এর।
