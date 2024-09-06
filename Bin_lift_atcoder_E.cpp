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
vector<vector<ll>>jump(64,vector<ll>(N,-1));
int32_t main()
{
    fast
    ll i,j=1,k=1,p,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        ll o=1;
        cin>>n>>q;
        vector<ll>v(n),ans;
        for(i=1;i<=n;i++)
        {
            cin>>k;
            jump[0][i]=k;
        }
        for(auto &it:v){cin>>it;}
        for(i=1;i<=62;i++)
        {
            for(j=1;j<=n;j++){jump[i][j]=jump[i-1][jump[i-1][j]];}
        }
        for(i=1;i<=n;i++)
        {
            k=i;
            for(j=62;j>=0;j--)
            {
                if((o<<j)&q){k=jump[j][k];}
            }
            ans.pb(k);
        }
        for(auto it:ans){cout<<v[it-1]<<" ";}cout<<endl;
    }
}
//https://atcoder.jp/contests/abc367/tasks/abc367_e
//বাইনারি লিফটিং।
