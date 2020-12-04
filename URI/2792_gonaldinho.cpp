#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int,int>
#define L 20
#define INF 1e9
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

int N, F[500005];
queue<int> resp;

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

    for(int i=1;i<=N;i++)
        update(i,1);

    for(int i=1;i<=N;i++){
        int X;
        cin>>X;
        resp.push(query(X));
        update(X,-1);
    }

    while(resp.size()){
        if(resp.size()!=1)
            cout<<resp.front()<<' ';
        else
            cout<<resp.front()<<endl;
        resp.pop();
    }

  return 0;
}

