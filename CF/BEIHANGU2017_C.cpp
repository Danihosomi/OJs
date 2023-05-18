#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (ll)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9+1
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int cor[200005];
ll n, sum[200005], ans, vis[200005];
vi v[200005];
set<int> c;

void dfs(int a,int b){
    vis[a]=1;
    sum[cor[a]]++;
    ll pre=sum[cor[a]];
    for(auto x : v[a]){
        if(x==b) continue;
        dfs(x,a);
        vis[a]+=vis[x];
        ans-=((vis[x]-sum[cor[a]]+pre)*((vis[x]-sum[cor[a]]+pre)-1))>>1;
        sum[cor[a]]+=(vis[x]-sum[cor[a]]+pre);
        pre=sum[cor[a]];
    }
}

int main(){_
    int t=1; 
    //cin>>t;
    //while(t--){
    //}

    while(cin>>n){
        cout<<"Case #"<<t<<": "; t++; ans=0;

        for(int i=1;i<=n;i++){ 
            cin>>cor[i];
            c.insert(cor[i]);
        }
        for(int i=1;i<n;i++){
            int a, b; cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }

        ans+=(sz(c)*((n*(n-1))>>1));
        dfs(1,1);

        for(auto x : c) ans-=(((n-sum[x])*(n-sum[x]-1))>>1);

        cout<<ans<<'\n';
        for(int i=0;i<=n;i++){
            v[i].clear(); vis[i]=sum[i]=cor[i]=0;
        } c.clear();
    }

    return 0;
}