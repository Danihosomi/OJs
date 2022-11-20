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

int n, dp[3][100005], v[3][100005];

int main(){_
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>v[j][i];

    dp[0][0]=v[0][0];
    dp[1][0]=v[1][0];
    dp[2][0]=v[2][0];

    for(int i=1;i<n;i++)
        for(int j=0;j<3;j++){
            if(!j) dp[j][i]=v[j][i]+max(dp[1][i-1],dp[2][i-1]);
            else if(j==1) dp[j][i]=v[j][i]+max(dp[0][i-1],dp[2][i-1]);
            else dp[j][i]=v[j][i]+max(dp[0][i-1],dp[1][i-1]);
        }

    cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<'\n';

    return 0;
}