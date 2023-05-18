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
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);

int N, Q, V[300005];
vi seg3[4*300002];

vi merge(vi &V1,vi &V2){
    int i=0, j=0;
    vi X;

    while(i<sz(V1) && j<sz(V2)){
        if(V1[i]<=V2[j]){
            X.eb(V1[i]);
            i++;
        }
        else{
            X.eb(V2[j]);
            j++;
        }
    }

    for(int k=i;k<sz(V1);k++)
        X.eb(V1[k]);
    for(int k=j;k<sz(V2);k++)
        X.eb(V2[k]);
    
    return X;
}

void build(int id,int l,int r){
    if(l==r){
        seg3[id].eb(V[l]);
        return ;
    }
    int meio=(l+r)>>1;
    build(L(id),l,meio);
    build(R(id),meio+1,r);

    seg3[id]=merge(seg3[L(id)],seg3[R(id)]);
}

int query(int id,int l,int r,int i,int j, int K){
    if(j<l || i>r) return 0;
    if(i<=l && r<=j)
        return (sz(seg3[id])-(lower_bound(all(seg3[id]),K)-seg3[id].begin()));
    

    int meio=(l+r)>>1;

    return query(L(id),l,meio,i,j,K)+query(R(id),meio+1,r,i,j,K);
}


int main(){_
    cin>>N>>Q;

    for(int i=1;i<=N;i++)
        cin>>V[i];
    
    build(1,1,N);

    while(Q--){
        int A, B, C; cin>>A>>B>>C;
        if(V[A]>=B)
            cout<<0<<'\n';
        else
            cout<<query(1,1,N,A,A+C,B)<<'\n';
    }

    return 0;
}
