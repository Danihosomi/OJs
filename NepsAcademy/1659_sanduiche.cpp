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
#define MAXN (int)1e5+5
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, M, V[21][21], dp[22][2100000];


int ans(int id,int mask){
    if(id>N)
        return mask!=0;

    if(dp[id][mask]!=-1)
        return dp[id][mask];

    int resp=0, check=0;
    resp+=ans(id+1,mask);
    for(int i=1;i<id;i++){
        if(mask&(1<<i) && V[i][id]){
            check++;
            break;
        }
    }
    if(!check)
        resp+=ans(id+1,mask|(1<<id));
    
    return dp[id][mask]=resp;
}

int main(){_
    cin>>N>>M;

    memset(dp,-1,sizeof(dp));

    while(M--){
        int A, B; cin>>A>>B;
        V[A][B]=1;
        V[B][A]=1;
    }

    cout<<ans(1,0)<<'\n';

    return 0; 
}