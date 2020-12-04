#include <bits/stdc++.h>
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

int N, pai[50005], dist[50005], resp, M[50005][MAXL];
vector<int> V[50005], par[25005];

void dfs(int A,int B){
    for(int i=0;i<V[A].size();i++){
        int X;
        X=V[A][i];
        if(X!=B){
            pai[X]=A;
            dist[X]=dist[A]+1;
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
    cin>>N;
    memset(M,-1,sizeof(M));

    for(int i=1;i<=N;i++){
        int A;
        cin>>A;
        par[A].push_back(i);
    }

    for(int i=1;i<N;i++){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
    pai[1]=1;
    dist[1]=1;
    dfs(1,1);

    for(int i=1;i<=N;i++)
        M[i][0]=pai[i];

    for(int j=1;j<MAXL;j++){
        for(int i=1;i<=N;i++){
            M[i][j]=M[M[i][j-1]][j-1];
        }
    }

    for(int i=1;i<=N/2;i++){
        int K;
        K=LCA(par[i][0],par[i][1]);
        resp+=dist[par[i][0]]+dist[par[i][1]]-2*dist[K];
    }

    cout<<resp<<endl;

	return 0;
}
