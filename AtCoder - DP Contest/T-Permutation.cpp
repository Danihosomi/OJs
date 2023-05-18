#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int inf = (int)1e9;
const ll mod = 1e9 + 7;
const ll linf = (ll)1e17;

int n;
ll dp[3005][3005];
string c;

int main(){_
    cin>>n>>c;
    
    dp[0][1]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            if(c[i-1]=='>') dp[i][j] = (dp[i-1][i]-dp[i-1][j-1]+mod)%mod;
            else dp[i][j] = dp[i-1][j-1];
            dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
        }
    }

    cout<<dp[n-1][n]<<'\n';

    return 0;
}