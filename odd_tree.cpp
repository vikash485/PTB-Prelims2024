#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
inline int bits(int n){
    return n==0 ? 0 : 1 + bits(n&(n-1));
}
int dp[2][2];
int f(int node,int par,vector<vector<pair<int,int>>>&adj,int level,int cur){
    int res=dp[!level][bits(cur)&1];
    dp[level][bits(cur)&1]+=2;
    for(auto &i:adj[node]){
        if(i.first==par)continue;
        res+=f(i.first,node,adj,!level,cur^i.second);
    }
    return res;
}
void solve(){
      int n,a,b,c;
      cin>>n;
      vector<vector<pair<int,int>>> adj(n+1) ;
      for (int i=1;i<n;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
      }
      int res=f(1,0,adj,0,0);
      res/=2;
      cout<<res<<'\n';  
}
 
signed main() {
    FastIO;
    int tt=1;
    // cin >> tt;
    while (tt--) {
        memset(dp,0,sizeof(dp));
        solve();
    }
    return 0;
}
