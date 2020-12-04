#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define ii pair<int,int>
#define L 20
#define INF 1e9
using namespace std;
typedef long long int ll;

int N, V[100005], F[100005];
char C;

void update(int A, int valor){
    while(A<=N){
        F[A]+=valor;
        A+=lsb(A);
    }
}

int query(int A){
    int ans=0;
    while(A>0){
        ans+=F[A];
        A-=lsb(A);
    }
    return ans;
}

int main(){_
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>V[i];
        update(i,V[i]);
    }

    while(cin>>C){
        if(C=='a'){
            int X;
            cin>>X;
            update(X,-V[X]);
        }
        else{
            int X;
            cin>>X;
            cout<<query(X)-V[X]<<endl;
        }
    }

  return 0;
}

