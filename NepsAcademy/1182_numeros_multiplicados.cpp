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

int N, M, K;
ll val[1005], ans[1005];
vector< ii > V[1005];

ll binpow(ll A,int E){
    ll ans = 1;
    while(E){
        if(E&1) 
			ans=(ans*A);
        
		A=(A*A);
        E>>=1;
    }
    return ans;
}

int main(){_
	cin>>M>>N>>K;

	for(int i=1;i<=N;i++)
		cin>>val[i];
	
	while(K--){
		int A, B, C;
		cin>>A>>B>>C;
		V[A].push_back({B,C});
	}
	
	ans[0]=1;
	for(int i=1;i<=M;i++){
		int X;
		X=V[i][0].first;
		if(!(val[X]&1))
			ans[i]=2;

		else{
			if(ans[i-1]==2) ans[i]=3;
			else ans[i]=ans[i-1]+2;
			for(;ans[i]<=sqrt(val[X]);ans[i]+=2)
				if(val[X]%ans[i]==0)
					break;
		}

		if(val[X]%ans[i]!=0)
			ans[i]=val[X];
		
		cout<<ans[i]<<' ';
		for(auto v : V[i])
			val[v.first]/=binpow(ans[i],v.second);
	}
	cout<<'\n';

    return 0;
}