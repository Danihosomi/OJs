#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (ll)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9+1
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

void setIO(string S) {
    freopen((S+".in").c_str(),"r",stdin);
    freopen((S+".out").c_str(),"w",stdout);
}

string a, b;
ll ans, v[30];

int main(){_
    setIO("concatenation");
    int t=1; 
    //cin>>t;
    while(t--){
    }

    cin>>a>>b; ans=sz(a)*sz(b);

    for(auto x : a) v[x-'a']++;
    v[a[0]-'a']--;

    for(int i=0;i<sz(b)-1;i++) ans-=v[b[i]-'a'];

    cout<<ans<<'\n';

    return 0;
}