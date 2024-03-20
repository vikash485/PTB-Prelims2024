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
const int N=2e5+1,mod=1e9+7;
int fact[N];

void check()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
}

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
    int a,b;
    cin>>a>>b;
    b/=2;
    int ans=0;
    int mid=a/2,lx=mid-b,uy=mid+b+1;
    for(int i=0;i<lx;i++)
    {
        int dx=i,dy=uy-1;
        int res=fact[dx+dy];
        res*=binaryExp(fact[dx],mod-2,mod);
        res%=mod;
        res*=binaryExp(fact[dy],mod-2,mod);
        res%=mod;
        dy++;
        int leftx=a-dx-1,lefty=a-dy-1;
        res*=fact[leftx+lefty];
        res%=mod;
        res*=binaryExp(fact[leftx],mod-2,mod);
        res%=mod;
        res*=binaryExp(fact[lefty],mod-2,mod);
        res%=mod;
        // cout<<i<<" "<<res<<endl;
        ans+=res;
        ans%=mod;
    }
    ans*=2;
    ans%=mod;
    cout<<ans<<endl;
}

signed main(){
    FastIO;
    check();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}