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

ll V[9];
unordered_map<string,ll> dist;
priority_queue< pair<ll,string>, vector< pair<ll,string> >, greater< pair<ll,string> > > P;
string S;

void func(string A){
    string aux=A;
    int X;
    for(int i=0;i<A.size();i++)
        if(A[i]=='0'){
            X=i;
            break;
        }
    if(X>2){
        swap(aux[X],aux[X-3]);
        if((!dist[aux] && aux!=S) || (dist[aux]>dist[A]+V[aux[X]-'0'])){
            dist[aux]=dist[A]+V[aux[X]-'0'];
            P.push({dist[aux],aux});
        }
        swap(aux[X],aux[X-3]);
    }
    if(X<6){
        swap(aux[X],aux[X+3]);
        if((!dist[aux] && aux!=S) || (dist[aux]>dist[A]+V[aux[X]-'0'])){
            dist[aux]=dist[A]+V[aux[X]-'0'];
            P.push({dist[aux],aux});
        }
        swap(aux[X],aux[X+3]);
    }
    if(X%3!=2){
        swap(aux[X],aux[X+1]);
        if((!dist[aux] && aux!=S) || (dist[aux]>dist[A]+V[aux[X]-'0'])){
            dist[aux]=dist[A]+V[aux[X]-'0'];
            P.push({dist[aux],aux});
        }
        swap(aux[X],aux[X+1]);
    }
    if(X%3){
        swap(aux[X],aux[X-1]);
        if((!dist[aux] && aux!=S) || (dist[aux]>dist[A]+V[aux[X]-'0'])){
            dist[aux]=dist[A]+V[aux[X]-'0'];
            P.push({dist[aux],aux});
        }
        swap(aux[X],aux[X-1]);
    }
}

void dijkstra(){
    P.push({0,S});
    while(!P.empty()){
        ll D; string atual;
        D=P.top().first;
        atual=P.top().second;
        P.pop();
        if(D>dist[atual]) continue;
        func(atual);
    }
}

int main(){_
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            char C; cin>>C;
            S+=C;
        }
    }

    for(int i=1;i<=8;i++)
        cin>>V[i];

    dijkstra();

    cout<<dist["123456780"]<<'\n';

    return 0;
}