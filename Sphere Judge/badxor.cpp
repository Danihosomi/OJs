#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int N, M, V[3005], vis[3005];
ll dp[3005][3005];
const ll mod=1e8+7;

ll ans(int id,int tam){
    if(id>=N){
        if(vis[tam])
            return 0;

        return 1;
    }

    if(dp[id][tam]!=-1)
        return dp[id][tam];

    ll resp=0;
    resp+=ans(id+1,tam)%mod;
    resp=(resp+ans(id+1,tam^V[id]))%mod;

    return dp[id][tam]=resp%mod;
}

int main(){_
    int T, g=1;
    cin>>T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        cin>>N>>M;

        for(int i=0;i<N;i++)
            cin>>V[i];

        for(int i=0;i<M;i++){
            int A;
            cin>>A;
            vis[A]++;
        }

        cout<<"Case "<<g<<": "<<ans(0,0)<<'\n';
        g++;
    }

    return 0;
}
