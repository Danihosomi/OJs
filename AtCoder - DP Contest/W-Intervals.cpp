#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int inf = (int)1e9;
const ll mod = 1e9 + 7;
const ll linf = (ll)1e17;

struct node{
    ll sum, lazy;
};

int n, m;
ll add[200005];
vector<pair<int,ll>> v[200005];
node seg3[4*200005];

ll join(ll a,ll b){
    return max(a,b);
}

void refresh(int id,int l,int r){
    if(!seg3[id].lazy) return;

    ll num=seg3[id].lazy; seg3[id].lazy=0;
    seg3[id].sum+=num;
    
    if(l==r) return ;
    seg3[L(id)].lazy+=num;
    seg3[R(id)].lazy+=num;
}

void update(int id,int l,int r,int i,int j,ll val){
    refresh(id,l,r);
    if(j<l || r<i) return;
    if(i<=l && r<=j){
        seg3[id].lazy+=val;
        refresh(id,l,r);
        return ;
    }
    
    int meio=(l+r)>>1;
    update(L(id),l,meio,i,j,val); update(R(id),meio+1,r,i,j,val);
    refresh(id,l,r); seg3[id].sum=join(seg3[L(id)].sum,seg3[R(id)].sum);    
}

ll query(int id,int l,int r,int i,int j){
    refresh(id,l,r);
    if(r<i || j<l) return -linf;
    if(i<=l && r<=j) return seg3[id].sum;
    int meio=(l+r)>>1;
    return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}

int main(){_
    cin>>n>>m;

    while(m--){
        ll a, b, c; cin>>a>>b>>c;
        add[a]+=c; v[b].pb({a,c});
    }

    for(int i=1;i<=n;i++){
        update(1,0,n,0,i-1,add[i]);
        update(1,0,n,i,i,query(1,0,n,0,i-1));
        for(auto x : v[i]) update(1,0,n,0,x.f-1,-x.s);
    }

    cout<<query(1,0,n,0,n)<<'\n';

    return 0;
}