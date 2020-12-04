#include <bits/stdc++.h>
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

ll N, pai[100005], dist[100005], M[100005][MAXL], Q;
ll resp, tot[100005];
vector< pair<ll,ll> > V[100005];

void dfs(ll A,ll B){
    for(int i=0;i<V[A].size();i++){
        ll X, D;
        X=V[A][i].first;
        D=V[A][i].second;
        if(X!=B){
            pai[X]=A;
            dist[X]=1+dist[A];
            tot[X]=D+tot[A];
            dfs(X,A);
        }
    }
}

int LCA(int A,int B){
    if(dist[A]<dist[B]) swap(A,B);

    for(int i=MAXL-1;i>=0;i--){
        if(dist[A]-(1<<i)>=dist[B])
            A=M[A][i];
    }

    if(A==B) return A;

    for(int i=MAXL-1;i>=0;i--){
        if(M[A][i]!=-1 && M[A][i]!=M[B][i]){
            A=M[A][i];
            B=M[B][i];
        }
    }

    return pai[A];
}


int main(){_
    while(cin>>N && N){
    memset(M,-1LL,sizeof(M));
    memset(pai,0LL,sizeof(pai));
    memset(dist,0LL,sizeof(dist));
    memset(tot,0LL,sizeof(tot));
    for(ll i=0;i<=N;i++){
        V[i].clear();
    }

    for(ll i=1;i<N;i++){
        ll B, C;
        cin>>B>>C;
        V[i].push_back({B,C});
        V[B].push_back({i,C});
    }

    pai[0]=0LL;
    dist[0]=1LL;
    tot[0]=0LL;
    dfs(0,0);

    for(int i=0;i<N;i++)
        M[i][0]=pai[i];

    for(int j=1;j<MAXL;j++){
        for(int i=0;i<N;i++){
            M[i][j]=M[M[i][j-1]][j-1];
        }
    }

    cin>>Q;

    while(Q--){
        resp=0;
        ll A, B, C;
        cin>>A>>B;
        C=LCA(A,B);
        resp=tot[A]+tot[B]-2*tot[C];
        cout<<resp<<" ";
    }
    cout<<endl;
    }

	return 0;
}

