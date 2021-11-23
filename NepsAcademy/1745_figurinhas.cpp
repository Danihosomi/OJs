#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, ini, qtd[100005], Q;
vi V[100005];

void dfs(int A,int B){
    qtd[A]|=qtd[B];
    for(auto v : V[A]){
        if(v==B) continue;
        dfs(v,A);
    }
}

int main(){_
    cin>>N>>ini;

    for(int i=1;i<=N;i++){
        int A; cin>>A;
        while(A--){
            int B; cin>>B;
            qtd[i]|=(1<<B);
        }
    }

    for(int i=1;i<N;i++){
        int A, B; cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }

    dfs(ini,ini);

    cin>>Q;
    while(Q--){
        int A; cin>>A;
        cout<<__builtin_popcount(qtd[A])<<'\n';
    }


    return 0;
}