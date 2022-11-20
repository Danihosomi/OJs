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

int l, c;
ll dp[1005][1005];
char m[1005][1005];

ll ans(int i,int j){
    if(i==l && j==c) return 1;
    if(i>l || j>c || m[i][j]=='#') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=(ans(i+1,j)+ans(i,j+1))%mod;
}

int main(){_
    cin>>l>>c; memset(dp,-1,sizeof(dp));

    for(int i=1;i<=l;i++)
        for(int j=1;j<=c;j++)
            cin>>m[i][j];
    
    cout<<ans(1,1)<<'\n';

    return 0;
}