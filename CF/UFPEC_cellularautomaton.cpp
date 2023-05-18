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

int N, K, Q;
string S, M;

int main(){_
    cin>>N>>K>>Q>>M>>S;

    while(Q--){
        string aux="";
        for(int i=0;i<S.size();i++){
            int aux2=0, cont=2*K;
            for(int j=-K;j<=K;j++){
                if(S[(i+j+N)%N]=='1'){
                    aux2|=(1<<cont);
                } 
                cont--;
            }
            aux+=M[M.size()-1-aux2];
        }
        S=aux;
    }

    cout<<S<<'\n';

    return 0;
}