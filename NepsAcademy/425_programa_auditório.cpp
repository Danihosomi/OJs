#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mk(x,y) make_pair(x,y)
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

int N, K, V[255], dp[255][64000];
pair<int,ii> memo[255][64000];

int ans(int id,int resta){
    if(resta<=0)
        return (!resta);
    if(id>N)
        return 0;
    if(dp[id][resta]!=-1)
        return dp[id][resta];
    int resp=0;
    resp|=ans(id+1,resta);
    if(resp){
        memo[id][resta]=mk(0,mk(id+1,resta));
    }
    else if(ans(id+1,resta-V[id])){
        resp|=ans(id+1,resta-V[id]);
        memo[id][resta]=mk(1,mk(id+1,resta-V[id]));
    }
    return dp[id][resta]=resp;
}

void func(int A,int B){
    if(memo[A][B].first)
        cout<<A<<' ';
    if(memo[A][B].second.second)
        func(memo[A][B].second.first,memo[A][B].second.second);
}

int main(){_
    cin>>N>>K;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<N;i++)
        cin>>V[i];

    if(ans(0,K)){
        cout<<'S'<<'\n';
        func(0,K);
        cout<<'\n';
    }
    else
        cout<<'N'<<'\n';

    return 0;
}