#include <bits/stdc++.h>
#define L 20
#define INF 100100
#define ii pair<int,int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int N, M, Q, pai[100010], peso[100010], up[100010][22], mup[100010][22], tin[100010], tout[100010], timer;
ll ans;
vector< ii > U[100010];
map< pair<int,int>, int> mapa;

struct aresta{
    int X, Y;
    ll P;
};

aresta V[200005];

int func(int A){
    if(A==pai[A])
        return A;

    return pai[A]=func(pai[A]);
}

bool comp(aresta A, aresta B){
    return A.P<B.P;
}

bool anc(int A, int B){
    return (tin[A]<=tin[B] && tout[B]<=tout[A]);
}

void join(int A, int B){
    A=func(A);
    B=func(B);

    if(A==B)
        return;

    if(peso[A]<peso[B]) swap(A,B);

    peso[A]+=peso[B];
    pai[B]=A;
    return;
}

void dfs(int A,int B,int W){
    tin[A]=timer;
    timer++;
    up[A][0]=B;
    mup[A][0]=W;
    for(int i=1;i<=L;i++){
        up[A][i]=up[ up[A][i-1] ][i-1];
        mup[A][i]=max(mup[A][i-1],mup[ up[A][i-1] ][i-1]);
    }

    for(int i=0;i<U[A].size();i++){
        int C, D;
        C=U[A][i].first;
        D=U[A][i].second;
        if(C!=B)
            dfs(C,A,D);
    }

    tout[A]=timer;
    timer++;
}

int lca(int A,int B){
    if(anc(A,B)) return A;
    if(anc(B,A)) return B;

    int C;
    C=A;
    for(int i=L;i>=0;i--){
        if(!anc(up[C][i],B))
            C=up[C][i];
    }

    return up[C][0];
}

int got(int A,int B){
    int K;
    K=-INF;

    int C;
    C=A;
    for(int i=L;i>=0;i--){
        if(!anc(up[C][i],B)){
            K=max(K,mup[C][i]);
            C=up[C][i];
        }
    }

    return max(K,mup[C][0]);
}

int maior(int A,int B){
    if(A==B) return 0;

    if(anc(A,B)) return got(B,A);

    if(anc(B,A)) return got(A,B);

    return max(got(A,lca(A,B)),got(B,lca(A,B)));
}

int main(){_
    cin>>N>>M;

    for(int i=1;i<=N;i++)
        pai[i]=i;

    for(int i=0;i<M;i++){
        int A, B;
        ll C;
        cin>>A>>B>>C;
        V[i].X=A;
        V[i].Y=B;
        V[i].P=C;
    }

    sort(V,V+M,comp);

    for(int i=0;i<M;i++){
        int j, k;
        j=V[i].X;
        k=V[i].Y;
        mapa[{max(j,k),min(j,k)}]=V[i].P;
        if(func(j)!=func(k)){
            U[j].push_back({k,V[i].P});
            U[k].push_back({j,V[i].P});
            join(j,k);
            ans+=V[i].P;
        }
    }

    dfs(1,1,0);

    cin>>Q;
    while(Q--){
        int A, B;
        cin>>A>>B;

        cout<<ans-maior(A,B)+mapa[{max(A,B),min(A,B)}]<<endl;
    }

    return 0;
}

