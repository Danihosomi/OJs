#include <bits/stdc++.h>
#define INF 1e9
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
using namespace std;
typedef long long int ll;

ll N, X, mod;
struct matriz{
    ll M[5][5];
};
matriz id, T, K;

matriz mult(matriz A, matriz B){
    matriz ans;

    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            ans.M[i][j]=0LL;
            for(int k=1;k<=2;k++){
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

int main(){
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            if(i==j)
                id.M[i][j]=1;
            else
                id.M[i][j]=0;
        }
    }
    K.M[1][1]=1;
    K.M[1][2]=1;
    while(cin>>N>>X){
        mod=1;
        while(X--){
            mod*=2;
        }
        T.M[1][1]=1;
        T.M[1][2]=1;
        T.M[2][1]=1;
        T.M[2][2]=0;
        T=expo(T,N);
       // T=mult(T,K);
        cout<<T.M[2][1]<<endl;
    }

    return 0;
}

