#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int Q;
ll ans;
map<char,int> C;
map<string,ll> M;
vi V;
string S;

int main(){_
    cin>>Q;

    while(Q--){
        cin>>S;
        for(auto c : S)
            C[c]++;

        for(auto v : C)
            V.eb(v.s);

        sort(all(V));
        S=to_string(sz(S));
        for(auto v : V)
            S+=to_string(v);
        
        M[S]++;
        C.clear();
        V.clear();
    }

    for(auto v : M)
        ans+=(v.s*(v.s-1))>>1;

    cout<<ans<<'\n';

    return 0;
}