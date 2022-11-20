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

int n, dp[100005], v[100005];

int main(){_
    cin>>n;
    for(int i=1;i<=n;i++) 
        dp[i]=inf+5, cin>>v[i];

    dp[1]=0;
    for(int i=2;i<=n;i++){
        if(i-1>=1) dp[i]=min(dp[i],abs(v[i]-v[i-1])+dp[i-1]);
        if(i-2>=1) dp[i]=min(dp[i],abs(v[i]-v[i-2])+dp[i-2]); 
    }


    cout<<dp[n]<<'\n';

    return 0;
}