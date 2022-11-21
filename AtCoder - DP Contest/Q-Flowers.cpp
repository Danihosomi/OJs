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
typedef pair<int,int> ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int n, h[200005];
ll seg3[4*200005], val[200005], dp[200005], ans;

ll join(ll a, ll b){
	return max(a,b);
}

void update(int id,int l,int r,int i,ll val){
	if(l==r && l==i){
		seg3[id]=val;
		return;
	}
	int meio=(l+r)>>1;
	if(meio>=i) update(L(id),l,meio,i,val);
	else update(R(id),meio+1,r,i,val);
	
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

ll query(int id,int l,int r,int i,int j){
	if(i<=l && r<=j) return seg3[id];
	if(r<i || j<l) return 0;
	int meio=(l+r)>>1;
	return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}

int main(){_
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=n;i++){
        dp[h[i]]=query(1,1,n,1,h[i])+val[i];
        update(1,1,n,h[i],dp[h[i]]); ans=max(ans,dp[h[i]]);
    }

    cout<<ans<<'\n';

    return 0;
}