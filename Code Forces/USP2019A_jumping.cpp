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
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, V[100005], seg3[4*100005];

int join(int A,int B){
	if(V[A]>=V[B])
        return A;
    return B;
}

void build(int id,int l,int r){
	if(l==r){
		seg3[id]=l;
		return;
	}
	int meio;
	meio=(l+r)>>1;
	build(L(id),l,meio);
	build(R(id),meio+1,r);
	seg3[id]=join(seg3[L(id)],seg3[R(id)]);
}

int query(int id,int l,int r,int K,int i){
    if(l==r)
        return l;
 
    int meio=(l+r)>>1;
    
    if(i<=l){
        if(V[seg3[L(id)]]>=K)
            return query(L(id),l,meio,K,i);
        if(V[seg3[R(id)]]>=K)
            return query(R(id),meio+1,r,K,i);
        return 0;
    }
    if(V[seg3[R(id)]]>=K && i>meio)
        return query(R(id),meio+1,r,K,i);
    
    if(i<=meio){
        int X, Y;
        X=query(L(id),l,meio,K,i);
        Y=query(R(id),meio+1,r,K,i);
        if(V[X]>=K && X>=i)
            return X;
        else if(V[Y]>=K && Y>=i)
            return Y;
        return 0;
    }
 
    return 0;
}

int main(){_
    cin>>N;

    for(int i=1;i<=N;i++)
        cin>>V[i];

    build(1,1,N);

    for(int i=1;i<N;i++){
        int X=query(1,1,N,V[i]+1,i);
        if(!X)
            cout<<min(N-i,V[i])<<' ';
        else
            cout<<min(X-1-i,V[i])<<' ';
    }
    cout<<0<<'\n';

    return 0;
}
