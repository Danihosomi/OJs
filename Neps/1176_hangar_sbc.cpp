#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
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

int N, K;
ll menor, maior;
vector<ll> V;

ll binomial(int n, int k) {
    if (n < k) return 0;
    if (k == 0 || k == n) return 1;
    ll prod = 1;
    for (int i = 1; i <= k; i++) {
        prod *= n + 1 - i;
        prod /= i;
    }
    return prod;
}
ll ans(int id,int falta,ll resta){
    if(falta==0)
       return 1;
    
    if(id==V.size() || resta<=0)
        return 0;

    if(V[id]>resta)
        return ans(id+1,falta,resta);
    
    return binomial(V.size()-id-1,falta)+ans(id+1,falta-1,resta-V[id]);
}

int main(){_
    cin>>N>>K;

    for(int i=0;i<N;i++){
        ll A; cin>>A;
        V.emplace_back(A);
    }
    
    cin>>menor>>maior;

    sort(V.rbegin(),V.rend());

    cout<<ans(0,K,maior)-ans(0,K,menor-1)<<'\n';

    return 0;
}