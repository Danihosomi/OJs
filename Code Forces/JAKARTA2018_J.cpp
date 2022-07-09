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

int N, dp[15][492000], tam[492000], qtd;
string S;
vector<string> V[15];
set<string> X;
set<int> V1[15];
map<string,int> M;

void getsub(int id,string atual,int k){
    if(id==sz(S))   return ;
    if(atual!=""){    
		X.insert(atual);
		V[k].eb(atual);
	}

    for(int i=id+1;i<sz(S);i++){
        atual+=S[i];
        getsub(i,atual,k);
        atual=atual.erase(atual.size()-1);
    }
}

int main(){_
	cin>>N; qtd++;

	for(int x=0;x<N;x++){
		cin>>S; getsub(-1,"",x);
		sort(all(V[x]));
	}
	
	for(auto x : X){
		M[x]=qtd; 
		tam[qtd]=sz(x);
		qtd++;
	}

	for(int i=0;i<N;i++){
		for(auto v : V[i])
			V1[i].insert(M[v]);

		dp[i][0]=-1;
	}

	for(int i=0;i<N;i++){
		for(int j=1;j<qtd;j++){
			dp[i][j]=dp[i][j-1];
			if(i==0){ 
				if(V1[i].count(j)){
					dp[i][j]=max(tam[j],dp[i][j]);
				}
			}
			else{ 
				if(V1[i].count(j) && dp[i-1][j-1]!=-1){ 
					dp[i][j]=max(tam[j]+dp[i-1][j-1],dp[i][j]);
				}
			}
		}
	}

	cout<<dp[N-1][qtd-1]<<'\n';

	return 0;
}