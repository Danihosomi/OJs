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

int L, C, vis[1000001];
vector<int> V[1000001];

void dfs(int A){
    vis[A]=1;
    for(auto v : V[A]){
        if(vis[v]) continue;
        dfs(v);
    }
}

int main(){_
    cin>>L>>C;

    for(int i=1;i<=L;i++){
        for(int j=1;j<=C;j++){
            int A; cin>>A;
            V[i*j].push_back(A);
        }
    }

    dfs(1);

    if(vis[L*C])
        cout<<"yes"<<'\n';
    else
        cout<<"no"<<'\n';

    return 0;
}