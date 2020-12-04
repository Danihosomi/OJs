#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int,int>
#define L 20
#define INF 2e5+10
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

ll N, K, up[5005][22], M, Q, tin[5005], tout[5005], timer;
ll dp[5005][1005];
ll grau[5005];
vector<ll> V[5005];
pair<ll,ll> C[5005];

void dfs(int A,int B){
    tin[A]=timer;
    timer++;
    up[A][0]=B;

    for(int i=1;i<=L;i++){
        up[A][i]=up[up[A][i-1]][i-1];
    }

    for(int i=0;i<V[A].size();i++){
        int X;
        X=V[A][i];
        if(X!=B)
            dfs(X,A);
    }
    tout[A]=timer;
    timer++;
}

bool anc(int A, int B){
    return (tin[A]<=tin[B] && tout[B]<=tout[A]);
}

int LCA(int A,int B){
    if(anc(A,B)) return A;
    if(anc(B,A)) return B;

    for(int i=L;i>=0;i--){
        if(!anc(up[A][i],B)){
            A=up[A][i];
        }
    }

    return up[A][0];
}

int dfs1(int A, int B){

    for(int i=0;i<V[A].size();i++){
        int X;
        X=V[A][i];
        if(X!=B)
            grau[A]+=dfs1(X,A);
    }

    return grau[A];
}

ll ans(int id, int resta){
    if(id>=M || !resta)
        return 0;

    if(dp[id][resta]!=-1)
        return dp[id][resta];

    ll nao;
    nao=ans(id+1,resta);

    if(resta-C[id].second>=0){
        ll sim;
        sim=grau[C[id].first]+ans(id+1,resta-C[id].second);

        return dp[id][resta]=max(sim,nao);
    }
    return dp[id][resta]=nao;
}

int main(){_
    cin>>N>>K;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<N;i++){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    cin>>M;

    for(int i=0;i<M;i++){
        cin>>C[i].first>>C[i].second;
    }

    dfs(1,1);

    cin>>Q;

    while(Q--){
        ll A, B, Y, X;
        cin>>A>>B>>Y;
        X=LCA(A,B);
        grau[A]+=Y;
        grau[B]+=Y;
        grau[X]-=Y;
        grau[up[X][0]]-=Y;
    }

    dfs1(1,1);

    cout<<ans(0LL,K)<<endl;

    return 0;
}

