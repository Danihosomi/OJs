#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n, k;
ll dp[105][100005], v[2][105];

int main(){_
    cin>>n>>k;

    for(int i=1;i<=n;i++) cin>>v[0][i]>>v[1][i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j-v[0][i]>=0) dp[i][j]=max(dp[i][j],v[1][i]+dp[i-1][j-v[0][i]]);
        }
    }

    cout<<dp[n][k]<<'\n';

    return 0;
}