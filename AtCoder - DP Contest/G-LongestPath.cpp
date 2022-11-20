#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n, m, dp[100005], ans;
vi v[100005];

int dfs(int a){
    if(dp[a]) return dp[a];
    for(auto x : v[a]) dp[a]=max(dp[a],dfs(x)+1);
    return dp[a];
}

int main(){_
    cin>>n>>m;

    while(m--){
        int a, b; cin>>a>>b;
        v[a].pb(b);
    }

    for(int i=1;i<=n;i++) ans=max(ans,dfs(i));
    cout<<ans<<'\n';

    return 0;
}