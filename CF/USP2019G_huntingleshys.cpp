#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, Q, V[100005], pai[100005];
 
pair<int,int> func(int A){
    if(A==pai[A])
        return {A,V[A]};
 
    V[A]=min(V[A],func(pai[A]).second);
    pai[A]=func(pai[A]).first;
    return {pai[A],V[A]};
}
 
void join(int A,int B){
    V[B]=min(V[B],func(A).second);
    A=func(A).first;
 
    if(A==B)
        return ;
 
    pai[B]=A;
}
 
int main(){_
    cin>>N>>Q;
 
    char C;
    int A, B;
 
    for(int i=1;i<=N;i++){
        cin>>V[i];
        pai[i]=i;
    }
 
    while(Q--){
        cin>>C;
        if(C=='?'){
            cin>>A;
            cout<<func(A).second<<'\n';
        }
        else{
            cin>>A>>B;
            join(A,B);
        }
    }
 
    return 0;
}