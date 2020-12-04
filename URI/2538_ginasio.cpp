#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int,int>
#define L 20
#define INF 2e5+5
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

int N, F[200010], IP, resp;

void update(int A, int valor){
    while(A<=INF){
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

    while(cin>>IP>>N){
        while(N--){
            int X, Y, aux;
            cin>>X>>Y;
            aux=query(X+IP)-query(X-IP-1);
            if(aux<=Y){
                resp++;
                update(X,1);
            }
        }
        cout<<resp<<endl;
        resp=0;
        memset(F,0,sizeof(F));
    }

  return 0;
}
