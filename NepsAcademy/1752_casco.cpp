#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, M, K, ini, fim;
ll dist[402005], ans=INF;
vector<pair<int,ll>> V[402005];
priority_queue< pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > P;

void dijkstra(){
    for(int i=0;i<=N*K+N;i++)
        dist[i]=INF;
    
    dist[ini]=0;
    P.push({0,ini});
    while(!P.empty()){
        int A; ll D;
        A=P.top().s;
        D=P.top().f;
        P.pop();
        if(D>dist[A]) continue;
        
        for(auto v : V[A]){
            if(dist[v.f]>v.s+D){
                dist[v.f]=v.s+D;
                P.push({dist[v.f],v.f});
            }
        }
    }
}

int main(){_
    cin>>K>>N>>M;

    while(M--){
        int A, B, C, D;
        cin>>A>>B>>C>>D;
        for(int i=0;i<=K-D;i++){
            V[A+N*i].push_back({B+N*(i+D),C});
            V[B+N*i].push_back({A+N*(i+D),C});
        }
    }
    cin>>ini>>fim;

    dijkstra();

    for(int i=0;i<K;i++)
        ans=min(ans,dist[fim+N*i]);

    cout<<(ans==INF ? -1 : ans)<<'\n';

    return 0;
}