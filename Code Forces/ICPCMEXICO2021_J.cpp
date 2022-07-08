#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define f first
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;

const ll mod = 1e9 + 7;

int n, tot, dp[1000005];
set<int> c;
vector<ii> v[1000005];

int ans(int tempo){
    if(tempo>=tot) return 0;
    if(~dp[tempo]) return dp[tempo];
    
    int resp=0;
    for(auto x : v[tempo])
        resp=max(resp,x.f+ans(tempo+x.s));

    resp=max(resp,ans((*c.lower_bound(tempo+1))));

    return dp[tempo]=resp;
}

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }

    cin>>n>>tot;

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++){
        int a, b, x; cin>>a>>b>>x;
        while(x--){
            int k; cin>>k;
            c.insert(k);
            v[k].pb({a,b});
        }
    }

    c.insert(tot);

    cout<<ans((*c.begin()))<<'\n';

    return 0;

}