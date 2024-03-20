#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//less_equal to ordered multiset

int mod=1e9+7;

int binaryExp(int a, int b, int mod)
{
    if(b==0)
    return 1;
    if(b==1)
    return a%mod;
    int ans=binaryExp(a,b/2,mod)%mod;
    ans*=ans;
    ans%=mod;
    if(b&1)
    ans*=a;
    ans%=mod;
    return ans%mod;
}

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(x>=v[i])
        {
            ans+=binaryExp(2,i+1,mod);
            ans%=mod;
            x-=v[i];
        }
    }
    cout<<ans<<endl;
}

signed main(){
    FastIO;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}