#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
using namespace std;
typedef long long int ll;

int N, M, Q, tin[1010], tout[1010], up[1010][22], timer, L=20;
vector<int> V[1010];

void dfs(int A,int B){
    tin[A]=timer;
    timer++;

    up[A][0]=B;
    for(int j=1;j<=L;j++){
        up[A][j]=up[up[A][j-1]][j-1];
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

bool anc(int A,int B){
    return tin[A]<=tin[B] && tout[B]<=tout[A];
}

int lca(int A,int B){
    if(anc(A,B)) return A;
    if(anc(B,A)) return B;

    int X=A;
    for(int i=L;i>=0;i--){
        if(!anc(up[X][i],B))
            X=up[X][i];
    }

    return up[X][0];
}

int main(){
    int T, id=1;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>M;
            while(M--){
                int A;
                cin>>A;
                V[A].push_back(i);
                V[i].push_back(A);
            }
        }
        dfs(1,1);

        cin>>Q;
        cout<<"Case "<<id<<":"<<endl;
        id++;
        while(Q--){
            int A, B;
            cin>>A>>B;
            cout<<lca(A,B)<<endl;
        }

        for(int i=0;i<=N;i++){
            tin[i]=0;
            tout[i]=0;
            V[i].clear();
        }
        timer=0;
        memset(up,0,sizeof(up));
    }

    return 0;
}

