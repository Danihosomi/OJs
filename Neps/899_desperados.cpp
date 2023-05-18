#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
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

struct aresta{
    int U, D;
};

int N, M, vis[1005], grau[1005], grau1[1005], conta, exis[1005][1005], id, ans;
vector<int> V[1005], G[1005], O, R[1005];
queue<int> Q;
aresta K[1000005];

void dfs(int A){
    vis[A]=1;
    for(int i=0;i<V[A].size();i++){
        int X=V[A][i];
        if(!vis[X])
            dfs(X);
    }
    O.push_back(A);
}

void dfs1(int A,int B){
    vis[A]=B;
    grau[B]++;
    for(int i=0;i<R[A].size();i++){
        int X;
        X=R[A][i];
        if(!vis[X])
            dfs1(X,B);
    }
}

int main(){_
    cin>>N>>M;

    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
        R[B].push_back(A);
        K[id].U=A;
        K[id].D=B;
        id++;
    }
    for(int i=1;i<=N;i++)
        if(!vis[i])
            dfs(i);

    for(int i=1;i<=N;i++)
        vis[i]=0;

    for(int i=O.size()-1;i>=0;i--){
        if(!vis[O[i]]){
            conta++;
            dfs1(O[i],conta);
        }
    }
    for(int i=0;i<id;i++){
        if(!exis[vis[K[i].U]][vis[K[i].D]] && vis[K[i].U]!=vis[K[i].D]){
            exis[vis[K[i].U]][vis[K[i].D]]=1;
            G[vis[K[i].U]].push_back(vis[K[i].D]);
            grau1[vis[K[i].D]]++;
        }
    }

    for(int i=1;i<=conta;i++){
        if(!grau1[i] && grau[i]<=3){
            Q.push(i);
            ans+=grau[i];
        }
    }

    while(!Q.empty()){
        int X;
        X=Q.front();
        Q.pop();
        for(int i=0;i<G[X].size();i++){
            int Y;
            Y=G[X][i];
            grau1[Y]--;
            if(!grau1[Y] && grau[Y]<=3){
                ans+=grau[Y];
                Q.push(Y);
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}