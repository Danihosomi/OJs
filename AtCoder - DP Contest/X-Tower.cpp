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

struct box{
    int peso, capa; ll val;
    int operator < (box a) const{
        if(capa-a.peso!=a.capa-peso) return (capa-a.peso)>(a.capa-peso);
        return val>a.val;
    }
};

int n;
ll dp[1005][10005];
vector<box> v;

ll ans(int id,int rest){
    if(id==n || !rest) return 0;
    if(dp[id][rest]!=-1) return dp[id][rest];

    ll resp=ans(id+1,rest);
    if(v[id].peso<=rest) resp=max(resp,v[id].val+ans(id+1,(rest==(int)1e4+1 ? v[id].capa : min(v[id].capa,rest-v[id].peso))));

    return dp[id][rest]=resp;
}

int main(){_
    cin>>n; memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        box a; cin>>a.peso>>a.capa>>a.val; v.pb(a);
    } sort(all(v));

    cout<<ans(0,(int)1e4+1)<<'\n';

    return 0;
}	