#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define ii pair<int,int>
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define INF 1e13
#define NEG -1e9+1
#define BUG(x) cout<<x<<endl;
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int Q, primo[10000001];

int main(){_
    cin>>Q;
    for(int i=2;i<=(int)1e7;i++){
        if(!primo[i])
            for(int j=1;j*i<=(int)1e7;j++)
                primo[i*j]+=1;
    }
    while(Q--){
        int A, B;
        cin>>A>>B;
        cout<<primo[A]+primo[B]-primo[__gcd(A,B)]<<'\n';
    }
    
    return 0;
}