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
#define MAXN (int)1e5+5
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N;
set<int> S;
ll V[200005], psa[200005];


int main(){_
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>V[i];
        psa[i]=psa[i-1]+V[i];
    }

    if(psa[N]%2){
        cout<<'N'<<'\n';
        return 0;
    }
    for(int i=0;i<N;i++){
        int ini, meio, fim;
        ini=1; fim=N;
        while(ini<fim){
            meio=ini+((fim-ini)>>1);
            if(psa[meio]-psa[i]>=psa[N]/2) fim=meio;
            else ini=meio+1;
        }
        if(psa[ini]-psa[i]==psa[N]/2){
            S.insert(ini);
            S.insert(i);
        }
        if(sz(S)==4){
            cout<<'S'<<'\n';
            return 0;
        }
    }

    cout<<'N'<<'\n';
    
    return 0; 
}