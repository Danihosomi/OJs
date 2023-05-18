#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n;
ll fat[400005], ans;

ll inv_mod(ll a,ll b){
    return (a > 1 ? b-inv_mod(b%a, a)*b/a : 1);
}

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }
    fat[0]=1;
    for(int i=1;i<=400000;i++) fat[i]=(i*fat[i-1])%mod;   
    cin>>n;

    for(int i=0;i<=n;i++){
        ll a; cin>>a;
        if(a)
            ans=(ans+(((fat[a+i]*inv_mod(fat[i+1],mod))%mod)*inv_mod(fat[a-1],mod))%mod)%mod;
    }

    cout<<ans<<'\n';

    return 0;
}