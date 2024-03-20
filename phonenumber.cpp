#include<bits/stdc++.h>
// #define int long long
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//less_equal to ordered multiset


void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum*=10;
        sum+=v[i];
    }
    // cout<<sum<<endl;
    int ans=sum;
    sum=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(v[i]!=0)
        {
            sum*=10;
            sum+=v[i];
            v.erase(v.begin()+i);
            n--;
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum*=10;
        sum+=v[i];
    }
    // cout<<sum<<endl;
    ans+=sum;
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