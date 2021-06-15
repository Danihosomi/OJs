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

int N, M, dp[2][100005];
vi V[100005];

int ans(int type,int id,int ant){
    if(dp[type][id]!=-1)
        return dp[type][id];
    
    int resp=0;
    for(auto v : V[id]){
        if(v==ant) continue;
        resp+=max(ans(type^1,v,id)+(!type),ans(type,v,id));
    }
    return dp[type][id]=resp;
}

int main(){_
    cin>>N>>M;

    memset(dp,-1,sizeof(dp));

    while(M--){
        int A, B;
        cin>>A>>B;
        V[A].eb(B);
        V[B].eb(A);
    }

    cout<<max(ans(1,1,1)+1,ans(0,1,1))<<'\n';

    return 0;
}