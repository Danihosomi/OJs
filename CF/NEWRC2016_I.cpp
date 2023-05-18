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
 
int n, m, k;
ll vis[3][100005], ans=inf;
vi c, o, v[100005], rv[100005];
queue<int> qu;
 
void bfs(int a){
    if(!a){
        vis[0][1]=0;
        qu.push(1);
        while(!qu.empty()){
            int x=qu.front(); qu.pop();
            for(auto y : v[x]){
                if(vis[0][y]==inf){
                    vis[0][y]=1+vis[0][x];
                    if(!y || y==n+1) vis[0][y]=vis[0][x];
                    qu.push(y);
                }
            }
        }
    }
    else{
        vis[a][(a==1 ? 0 : n+1)]=0;
        qu.push((a==1 ? 0 : n+1));
        while(!qu.empty()){
            int x=qu.front(); qu.pop();
            for(auto y : rv[x]){
                if(vis[a][y]==inf){
                    vis[a][y]=1+vis[a][x];
                    if(!x || x==n+1) vis[a][y]--;
                    qu.push(y);
                }
            }
        }
    }
}
 
int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }
 
    cin>>n>>m>>k;
 
    for(int i=0;i<=n+1;i++) vis[0][i]=vis[1][i]=vis[2][i]=inf;
    
 
    for(int i=0;i<m;i++){
        int a; cin>>a; c.pb(a); v[a].pb(n+1); rv[n+1].pb(a);
    }
    for(int i=0;i<k;i++){
        int a; cin>>a; o.pb(a); v[a].pb(0); rv[0].pb(a);
    }
 
    for(int i=1;i<=n;i++){
        int q; cin>>q;
        while(q--){
            int a; cin>>a;
            v[i].pb(a);
            rv[a].pb(i);
        }
    }
 
    bfs(0); bfs(1); bfs(2);
 
    for(int i=1;i<=n;i++) ans=min(ans,vis[1][i]+vis[2][i]+vis[0][i]);
 
    if(ans==inf) cout<<"impossible"<<'\n';
    else cout<<ans<<'\n';
 
    return 0;
}