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

int n;
ll dp[2][100005];
vi v[100005];

ll ans(int cor,int a,int p){
    if(dp[cor][a]!=-1) return dp[cor][a];

    ll resp=1;
    for(auto x : v[a]){
        if(x==p) continue;
        if(cor) resp=(resp*ans(cor^1,x,a))%mod;
        else resp=(resp*(ans(cor^1,x,a)+ans(cor,x,a)))%mod;
    }

    return dp[cor][a]=(resp ? resp : 1);
}

int main(){_
    cin>>n; memset(dp,-1,sizeof(dp));
    for(int i=1;i<n;i++){
        int a, b; cin>>a>>b; 
        v[a].pb(b); v[b].pb(a);
    }

    cout<<(ans(1,1,1)+ans(0,1,1))%mod<<'\n';

    return 0;
}