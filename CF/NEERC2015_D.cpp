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

void setIO(string S) {
    freopen((S+".in").c_str(),"r",stdin);
    freopen((S+".out").c_str(),"w",stdout);
}

ll n;
vector<ll> ans;

int main(){_
    setIO("distribution");
    int t = 1;
    cin>>t;
    while(t--){

        cin>>n; ans.clear();
        ll p2=1;
        while(n){
            while(n%2==0){
                p2*=2; n/=2;
            }

            ll p3=1;
            while(p3*3<=n) p3*=3;
            n-=p3; ans.pb(p3*p2);
        }

        cout<<sz(ans)<<'\n';
        for(auto a : ans) cout<<a<<' ';
        cout<<'\n';
    }

    return 0;
}