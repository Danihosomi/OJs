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

struct node{
    int imin, imax;
};

int n, v[250005], ans, nextg[250005], nextm[250005];
stack<ii> p;
node seg3[4*250005], neutro;

node join(node a, node b){
	node novo;
    if(!a.imin) return b;
    if(!b.imin) return a;
    
    if(v[a.imin]<=v[b.imin]) novo.imin=a.imin;
    else novo.imin=b.imin;
    
    if(v[a.imax]<v[b.imax]) novo.imax=b.imax;
    else novo.imax=a.imax;
    
    return novo;
}

void build(int id,int l,int r){
	if(l==r){
		seg3[id].imin=seg3[id].imax=l;
		return;
	}
	int meio=(l+r)>>1;
	build(L(id),l,meio);
	build(R(id),meio+1,r);
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

node query(int id,int l,int r,int i,int j){
	if(i<=l && r<=j) return seg3[id];
	if(r<i || j<l) return neutro;
	int meio=(l+r)>>1;
	return join(query(L(id),l,meio,i,j),query(R(id),meio+1,r,i,j));
}

int main(){_
    int t = 1;
    cin>>t; neutro={0,0};
    while(t--){
        cin>>n; ans=0;
        for(int i=1;i<=n;i++) cin>>v[i];
        build(1,1,n);
        for(int i=1;i<=n;i++){
            while(!p.empty() && p.top().f>v[i]){
                nextm[p.top().s]=i;
                p.pop();
            }
            p.push({v[i],i});
        }
        
        while(!p.empty()){
            nextm[p.top().s]=n;
            p.pop();
        }
        
        for(int i=1;i<=n;i++){
            while(!p.empty() && p.top().f<v[i]){
                nextg[p.top().s]=i;
                p.pop();
            }
            p.push({v[i],i});
        }
        
        while(!p.empty()){
            nextg[p.top().s]=n;
            p.pop();
        }
        
        int id=1;
        while(id!=n){
            node x;
            if(v[id+1]>v[id]){
                x=query(1,1,n,id,nextm[id]);
                id=x.imax;
            }
            else{
                x=query(1,1,n,id,nextg[id]);
                id=x.imin;
            }
            ans++;
        }
        
        cout<<ans<<'\n';
    }

    return 0;

}