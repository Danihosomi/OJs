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

int n, k, v[105], dp[2][100005];

int ans(int id,int resta){
    if(!resta) return id;
    if(dp[id][resta]!=-1) return dp[id][resta];

    int resp=id;
    for(int i=0;i<n;i++) 
        if(resta-v[i]>=0){ 
            if(id) resp=min(resp,ans(id^1,resta-v[i]));
            else resp=max(resp,ans(id^1,resta-v[i]));
        }
    
    return dp[id][resta]=resp;
}

int main(){_
    cin>>n>>k; memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<(ans(0,k) ? "First" : "Second")<<'\n';

    return 0;
}