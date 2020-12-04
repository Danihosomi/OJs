#include <bits/stdc++.h>
#define INF -1000000
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int,int>
#define MAX 5
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

ll N;
const ll mod=1000000009;
struct matriz{
    ll M[MAX][MAX];
};
matriz id, T, K;

matriz mult(matriz A, matriz B){
    matriz ans;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            ans.M[i][j]=0LL;
            for(int k=1;k<=3;k++){
                ans.M[i][j]+=(A.M[i][k]*B.M[k][j]);
            }
            ans.M[i][j]=(ans.M[i][j]+mod)%mod;
        }
    }
    return ans;
}


matriz expo(matriz B,ll E){
    matriz ans;
    ans=id;

    while(E){
        if(E&1) ans=mult(ans,B);
        B=mult(B,B);
        E>>=1;
    }
    return ans;
}

int main(){_
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(i==j) id.M[i][j]=1LL;

    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            K.M[i][j]=0LL;

    K.M[1][1]=1LL;
    K.M[3][1]=-1LL;
    while(cin>>N && N){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                T.M[i][j]=0LL;

        for(int i=1;i<=3;i++){
            T.M[1][i]=1LL;
        }
        T.M[2][1]=1LL;
        T.M[3][2]=1LL;
        T=expo(T,N);
        T=mult(T,K);
        cout<<T.M[1][1]<<endl;
    }

    return 0;
}

