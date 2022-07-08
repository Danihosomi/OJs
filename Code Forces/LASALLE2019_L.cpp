#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int l, c, m[1005][1005], cnt, ans, vis[1000005];
vi v[1000005];
ll k;

void dfs(int a){
    vis[a]=1;
    for(auto x : v[a]){
        if(vis[x]) continue;
        dfs(x);
    }
}

ll binpow(ll A,ll E){
    ll ans = 1;
    while(E){
        if(E&1) 
			ans=(ans*A)%mod;
        
		A=(A*A)%mod;
        E>>=1;
    }
    return ans;
}

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }

    cin>>k>>l>>c; cnt=1;

    for(int i=1;i<=l;i++)
        for(int j=1;j<=c;j++) m[i][j]=cnt++;
    
    int atualx=1, atualy=c;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            v[m[i][j]].pb(m[atualx][atualy]);
            v[m[atualx][atualy]].pb(m[i][j]);
            atualx++;
            if(atualx>l){
                atualx=1;
                atualy--;
            }
        }
    }

    for(int i=1;i<=l;i++)
        for(int j=1;j<=c;j++)
            if(!vis[m[i][j]]){
                ans++;
                dfs(m[i][j]);
            }
        
    cout<<binpow(k,ans)<<'\n';

    return 0;
}