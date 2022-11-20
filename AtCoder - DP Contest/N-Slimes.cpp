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
ll psa[405], dp[405][405], v[405];

ll ans(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    ll resp=linf;
    for(int i=l;i<r;i++) resp=min(resp,ans(l,i)+ans(i+1,r)+psa[r]-psa[l-1]);
    return dp[l][r]=resp;
}

int main(){_
    cin>>n; memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>v[i]; psa[i]=v[i]+psa[i-1];
    }
    cout<<ans(1,n)<<'\n';
    return 0;
}