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

string x;
vi v;
int d;
ll dp[2][105][100005];

vi digit(string a){
    vi dig; for(auto x : a) dig.pb(x-'0');
    return dig;
}

ll ans(int t,int sum,int id){
    if(id==sz(v)) return !sum;
    if(dp[t][sum][id]!=-1) return dp[t][sum][id];

    ll resp=0;
    if(t)
        for(int i=0;i<=9;i++) resp=(resp+ans(t,(sum+i)%d,id+1))%mod;
    else
        for(int i=0;i<=v[id];i++) resp=(resp+ans(i!=v[id],(sum+i)%d,id+1))%mod;

    return dp[t][sum][id]=resp;
}

int main(){_
    cin>>x>>d; v=digit(x);
    memset(dp,-1,sizeof(dp));
    cout<<(ans(0,0,0)-1+mod)%mod<<'\n';

    return 0;
}	