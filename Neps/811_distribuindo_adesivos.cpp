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

int N, M, K;
ll dp[2005][2005];

int main(){_
    cin>>N>>M>>K;

    dp[0][0]=1;

    for(int i=0;i<=M;i++){
        for(int j=0;j<=N;j++){
            if(i-1>=0){
                if(j-1>=0)
                    dp[i][j]=(dp[i-1][j-1])%mod;
                if(j-K>=0)
                    dp[i][j]=(dp[i][j]-dp[i-1][j-K-1]+mod)%mod;
            }
            else
                break;
        }
        for(int j=1;j<=N;j++){
            dp[i][j]+=dp[i][j-1];
        }
    }

    cout<<(dp[M][N]-dp[M][N-1]+mod)%mod<<'\n';   

    return 0;
}