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
const ll linf = (ll)1e17;

int n;
ll mod, in[100005], out[100005];
vi v[100005];

void findIn(int a,int p){
    in[a]=1;
    for(auto x : v[a]){
        if(x==p) continue;
        findIn(x,a); in[a] = (in[a]*in[x])%mod;
    }
    in[a]=(in[a]+1)%mod;
}

void findOut(int a,int p){
    ll prefix = out[a];

    for(auto x : v[a]){
        if(x==p) continue;
        if(!out[x]) out[x]=1;
        out[x] = (out[x]*prefix)%mod;
        prefix = (in[x]*prefix)%mod;
    }

    prefix = 1; 
    for(int i=sz(v[a])-1;i>=0;i--){
        int x = v[a][i];
        if(x==p) continue;
        out[x] = (out[x]*prefix)%mod;
        prefix = (prefix*in[x])%mod;
    }

    for(auto x : v[a]){
        if(x==p) continue;
        out[x] = (out[x]+1)%mod;
        findOut(x,a);
    }

}

int main(){_
    cin>>n>>mod; 

    for(int i=1;i<n;i++){
        int a, b; cin>>a>>b;
        v[a].pb(b); v[b].pb(a);
    }
    out[1]=1; findIn(1,1); findOut(1,1);

    for(int i=1;i<=n;i++) cout<<(((in[i]-1+mod)%mod)*out[i])%mod<<'\n';

    return 0;
}