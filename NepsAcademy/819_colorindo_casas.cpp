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

int N, qtd[2];
vi V[100005];

void dfs(int A,int pai,int cor){
    qtd[cor]++;
    for(auto v : V[A]){
        if(v==pai) continue;
        dfs(v,A,cor^1);
    }
}

int main(){_
    cin>>N;

    for(int i=1;i<N;i++){
        int A, B;
        cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }

    dfs(1,1,0);

    if(qtd[1]==qtd[0])
        cout<<'Y'<<'\n';
    else
        cout<<'N'<<'\n';

    return 0;

}