#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<double,double>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef unsigned long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int L, C, K;
vector< vi > dp, M;

int ans(int i,int j){
    if(i>L || j>C || !M[i][j])
        return 0;
    
    if(i==L && j==C)
        return 1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int resp=0;
    resp=(resp+ans(i+1,j))%mod;
    resp=(resp+ans(i,j+1))%mod;
    return dp[i][j]=resp;
}

int main() {_
    cin>>L>>C>>K;

    swap(L,C);

    dp.resize(L+1);
    for(int i=0;i<=L;i++)
        dp[i].assign(C+1,-1);

    M.resize(L+1);
    for(int i=0;i<=L;i++)
        M[i].resize(C+1);

    while(K--){
        int A, B; cin>>A>>B;
        M[A][B]=1;
    }

    cout<<ans(1,1)<<'\n';

    return 0;
}