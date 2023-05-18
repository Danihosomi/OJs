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

int N;
string S;
vi V;

void back(int id,int sum){
    if(id==N){
        V.eb(sum);
        return ;
    }
    
    back(id+1,sum);
    back(id+1,(int)S[id]+sum);
}

int main(){_
    cin>>N>>S;

    back(0,0);
    sort(all(V));
    for(auto v : V)
        cout<<v<<' ';
    cout<<'\n';

    return 0;
}