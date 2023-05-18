#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

int N, K;
ll dp[1005][5][5];

ll ans(int id, int resta, int rei){
    if(id==N){
        if((resta==1 && !rei) || (!resta && !rei))
            return 1;
        return 0;
    }
    if(dp[id][resta][rei]!=-1)
        return dp[id][resta][rei];

    ll resp;
    if(resta==2){
        resp=ans(id+1,resta,rei)+ans(id+1,resta-1,rei);
    }

    else if(resta==1){
            if(rei)
                resp=ans(id+1,resta,rei)+ans(id+1,resta,rei-1);
            else
                resp=ans(id+1,resta,rei)+ans(id+1,resta-1,rei);
    }

    else{
        resp=ans(id+1,resta,rei);
    }

    return dp[id][resta][rei]=resp;
}

int main(){_
    memset(dp,-1,sizeof(dp));

    cin>>N>>K;

    if(K==2)
        cout<<ans(1,2,1)<<endl;

    else{
        ll resp=1;
        for(int i=N;i>(N-1-K);i--){
            resp*=i;
        }

        cout<<resp<<endl;
    }

	return 0;
}
