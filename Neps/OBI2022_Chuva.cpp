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

int n, k;
ll ans, sum;
map<ll,ll> m;

int main(){_

    int t = 1;
    //cin>>t;

    while(t--){
    }
    m[0]=1;
    cin>>n>>k;
    
    while(n--){
        int a; cin>>a;
        sum+=a; ans+=m[sum-k];
        m[sum]++;
    }

    cout<<ans<<'\n';

    return 0;

}