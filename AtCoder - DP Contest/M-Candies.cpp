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
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n, k;
vi v;
ll dp[100005], psa[100005];

int main(){_
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        int a; cin>>a; v.pb(a);
    }   
    
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++) psa[j]=0;
        
        for(int j=k;j>=0;j--)
            if(1<=min(v[i],k-j)) psa[j+1]=(psa[j+1]+dp[j])%mod, psa[j+min(v[i],k-j)+1]=(psa[j+min(v[i],k-j)+1]-dp[j]+mod)%mod;

        for(int j=0;j<=k;j++){  
            if(j) psa[j]=(psa[j]+psa[j-1])%mod;
            dp[j]=(dp[j]+psa[j])%mod;
        }
    }

    cout<<dp[k]<<'\n';
    
    return 0;
}