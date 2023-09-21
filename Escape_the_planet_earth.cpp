//https://toph.co/p/escape-the-planet-earth
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl;
#define endl '\n'
const ll M =1e9+7;
const ll N =1e2+1;
int32_t main()
{
    fast
    ll i,j,n,m,k,q,tc=1,cs=0;//cin>>tc;
    while(tc--)
    {
        cin>>n;vector<ll>v(n),a,b,x,y;
        for(i=0;i<n;i++)
        {
            cin>>v[i];
            if(i&1){a.pb(v[i]);}
            else{b.pb(v[i]);}
        }
        for(i=0;i<(1<<a.size());i++)
        {
            k=0;
            for(j=0;j<a.size();j++)
            {
                if((i>>j)&1){k+=a[j];}
            }
            x.pb(k);
        }
        for(i=0;i<(1<<b.size());i++)
        {
            k=0;
            for(j=0;j<b.size();j++)
            {
                if((i>>j)&1){k+=b[j];}
            }
            y.pb(k);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        cin>>q;
        while(q--)
        {
            ll l,r,L,R,ans=0;cin>>l>>r;
            L=lower_bound(x.begin(),x.end(),l)-x.begin();
            R=lower_bound(x.begin(),x.end(),r+1)-x.begin();
            for(i=0;i<R;i++)
            {
                ll p,q,P,Q;
                p=r-x[i];
                P=upper_bound(y.begin(),y.end(),p)-y.begin();
                q=l-x[i];
                Q=lower_bound(y.begin(),y.end(),q)-y.begin();
                ans+=P-Q;
            }
            cout<<ans<<endl;
        }
    }
}

/*
যা যা জানা প্রয়োজন
১)বাইনারি সার্চ বেসিক কন্সেপ্ট।(upper_bound/lower_bound);
২) বিট মাস্কিং এর সাহায্যে অল পসিবল সাবসেট জেনারেট করার টেকনিক।
৩) Meet in the middle টেকনিক।
*/

