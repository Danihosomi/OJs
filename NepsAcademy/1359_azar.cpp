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

ll dp[1050000], fato[21], gdc;
int N;

ll ans(int mask){
    if(mask==(1<<N)-1)
        return 1;
    
    if(dp[mask]!=-1)
        return dp[mask];
    
    ll resp=0;
    int qtd=__builtin_popcount(mask);
    for(int i=0;i<N;i++){
        if(!(mask&(1<<i)) && qtd!=i)
            resp+=ans(mask|(1<<i));
    }

    return dp[mask]=resp;
}

int main(){_
    cin>>N;
    memset(dp,-1,sizeof(dp));

    fato[1]=1;
    for(int i=2;i<=N;i++)
        fato[i]=i*fato[i-1];

    ll resp=ans(0);
    gdc=__gcd(resp,fato[N]);

    cout<<resp/gdc<<'/'<<fato[N]/gdc<<'\n';

    return 0;
}