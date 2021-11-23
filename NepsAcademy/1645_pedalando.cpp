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

int N, M, dist[105][105], Q;

void FW(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));
            }
        }
    }
}

int main(){_
    cin>>N>>M;
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            dist[i][j]=INF;

    while(M--){
        int A, B, C; cin>>A>>B>>C;
        dist[A][B]=dist[B][A]=min(C,dist[A][B]);
    }

    FW();

    cin>>Q;

    while(Q--){
        int A, B; cin>>A>>B;
        if(A!=B)
            cout<<dist[A][B]<<'\n';
        else
            cout<<0<<'\n';
    }

    return 0;
}