#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int inf = (int)1e9;
const ll mod = 1e9 + 7;
const ll linf = (ll)1e17;

ll inv_mod(ll a,ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}

int l, c, n;
vector<ii> v;
ll dp[3005], fat[200005], ifat[200005];

void init(){
    fat[0]=1; ifat[0]=inv_mod(1,mod);
    for(int i=1;i<=(int)2e5;i++){ 
        fat[i]=(i*fat[i-1])%mod;
        ifat[i]=inv_mod(fat[i],mod);
    }
}

ll binomial(int x,int y){
    return (((fat[x+y]*ifat[x])%mod)*ifat[y])%mod;
}

int main(){_
    cin>>l>>c>>n;

    init();

    for(int i=0;i<n;i++){
        ii a; cin>>a.f>>a.s; v.pb(a);
    } v.pb({l,c}); sort(all(v));

    for(int i=0;i<=n;i++){
        dp[i] = binomial(v[i].s-1,v[i].f-1);
        for(int j=0;j<i;j++)
            if(v[j].f<=v[i].f && v[j].s<=v[i].s) dp[i]=(dp[i]-((dp[j]*binomial(v[i].f-v[j].f,v[i].s-v[j].s))%mod)+mod)%mod;
    }

    cout<<dp[n]<<'\n';

    return 0;
}