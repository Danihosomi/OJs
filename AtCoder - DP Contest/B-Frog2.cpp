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

int n, k, dp[100005], v[100005];

int main(){_
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
        dp[i]=inf+5, cin>>v[i];

    dp[1]=0;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=k;j++)
            if(i-j>=1) dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));


    cout<<dp[n]<<'\n';

    return 0;
}