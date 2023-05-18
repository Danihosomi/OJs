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

int N;
string ini, fim;
unordered_map<string,int> dist;
queue<string> Q;

string comp(string A,int B,int C){
    if(A[B+C]=='A')
        A[B+C]='X';
    else if(A[B+C]=='X')
        A[B+C]='M';
    else if(A[B+C]=='M')
        A[B+C]='A';
    return A;
}

void func(string X){
    string aux=X;
    for(int i=0;i<aux.size();i++){
        aux=comp(aux,i,0);
        if(N==2){
            if(i!=1 && i!=3)
                aux=comp(aux,i,1);
            if(i!=0 && i!=2)
                aux=comp(aux,i,-1);
            if(i+2<4)
                aux=comp(aux,i,2);
            if(i-2>-1)
                aux=comp(aux,i,-2);
        }
        else{
            if(i!=2 && i!=5 && i!=8)
                aux=comp(aux,i,1);
            if(i!=0 && i!=3 && i!=6)
                aux=comp(aux,i,-1);
            if(i+3<9)
                aux=comp(aux,i,3);
            if(i-3>-1)
                aux=comp(aux,i,-3);
        }

        if(!dist[aux]){
            dist[aux]=dist[X]+1;
            Q.push(aux);
        }
        aux=X;
    }
}

void bfs(){
    Q.push(ini);
    dist[ini]=1;
    while(!Q.empty()){
        string X=Q.front();
        Q.pop();
        func(X);
    }
}

int main(){_
    cin>>N;

    for(int i=1;i<=N;i++){
        string S; cin>>S;
        ini+=S;
    }
    if(N==2)
        fim="AAAA";
    else
        fim="AAAAAAAAA";

    bfs();

    if(!dist.count(fim))
        cout<<-1<<'\n';
    else
        cout<<dist[fim]-1<<'\n';
 
    return 0;
}