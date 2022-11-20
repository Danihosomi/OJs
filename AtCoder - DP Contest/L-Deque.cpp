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

int n, see[2][3005][3005];
ll dp[2][3005][3005], v[3005];

ll ans(int i,int l,int r){
    if(l>r) return 0;
    if(see[i][l][r]) return dp[i][l][r];
    see[i][l][r]=1;
    if(!i) dp[i][l][r]=max(v[l]+ans(i^1,l+1,r),v[r]+ans(i^1,l,r-1));
    else dp[i][l][r]=min(-v[l]+ans(i^1,l+1,r),-v[r]+ans(i^1,l,r-1));
    return dp[i][l][r];
}

int main(){_
    cin>>n; for(int i=0;i<n;i++) cin>>v[i];
    cout<<ans(0,0,n-1)<<'\n';
    return 0;
}