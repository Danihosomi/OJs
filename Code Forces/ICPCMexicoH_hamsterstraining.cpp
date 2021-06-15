#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define INF 1e13
#define NEG -1e9+1
#define BUG(x) cout<<x<<endl;
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

ll inv_mod(ll a, ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}

int Q, N;
ll dp[200000], idp[200005], ans;

int main(){_
    cin>>Q;
    dp[0]=1;
    for(int i=1;i<=(int)(2*1e5)-1;i++)
        dp[i]=(i*dp[i-1])%mod;
    
    for(int i=(int)(2*1e5)-1;i>=0;i--)
        idp[i]=inv_mod(dp[i],mod);

    while(Q--){
        cin>>N;
        ans=dp[(2*N)-1];
        ans=(ans*idp[N])%mod;
        ans=(ans*idp[N-1])%mod;
        cout<<ans<<'\n';
    }

    return 0;
}