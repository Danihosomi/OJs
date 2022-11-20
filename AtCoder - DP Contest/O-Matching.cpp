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

int n, m[25][25];
ll dp[21][(1<<21)];

ll ans(int id,int mask){
    if(id==n) return __builtin_popcount(mask)==n;
    if(dp[id][mask]!=-1) return dp[id][mask];

    ll resp=0;
    for(int i=0;i<n;i++)
        if(!(mask&(1<<i)) && m[id][i]) resp=(resp+ans(id+1,mask|(1<<i)))%mod;

    return dp[id][mask]=resp;
}

int main(){_
    cin>>n; memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];

    cout<<ans(0,0)<<'\n';

    return 0;
}