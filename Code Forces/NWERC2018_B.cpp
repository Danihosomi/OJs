#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define s second
#define f first
#define sz(x) (long long)x.size()

typedef pair<long long,int>ii;
typedef vector<int> vi;

const int mod = 1e9 + 7;

int n, g[400005], visited[400005];
ll val[400005], maior[400005], ans;
vi v[400005], vis;
priority_queue<ii> p;

ll dfs(int a){
    if(visited[a])
        return maior[a];

    visited[a]=1;
    for(auto x : v[a]){
        maior[a]=max(maior[a],dfs(x));
    }

    return maior[a];
}

int main(void) {_
    int t = 1;
    //cin>>t;

    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            int k, a;
            cin>>val[i]>>k; g[i]=k; maior[i]=val[i];
            while(k--){
                cin>>a;
                v[a].pb(i);
            }
        }

        for(int i=1;i<=n;i++){
            if(!g[i]){ 
                dfs(i); p.push({maior[i],i});
            }
        }

        while(!p.empty()){
            int x=p.top().s;
            ans=max(ans,val[x]+sz(vis));
            p.pop();
            for(auto u : v[x]){
                g[u]--;
                if(!g[u]) p.push({maior[u],u});
            }
            vis.pb(x);
        }

        cout<<ans<<'\n';
    }
    return 0;
}