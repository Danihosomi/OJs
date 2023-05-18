#include <bits/stdc++.h>
#define INF 1e9+5
#define pii pair<int,int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
using namespace std;
typedef long long int ll;

priority_queue< pii, vector< pii >, greater< pii > > P;
int N, M, dist[1005], temp[1005], menor;
vector< pii > V[1005];

void Dijkstra(int A){
    for(int i=1;i<=N;i++)
        dist[i]=INF;

    P.push({0,A});

    while(!P.empty()){
        int X, D;
        X=P.top().second;
        D=P.top().first;
        P.pop();

        if(D>dist[X]) continue;

        for(int i=0;i<V[X].size();i++){
            int Y, dis;
            Y=V[X][i].first;
            dis=V[X][i].second+temp[Y]+D;
            if(dist[Y]>dis){
                dist[Y]=dis;
                P.push({dist[Y],Y});
            }
        }
    }
}

int main(){_
    cin>>N>>M;
    menor=INF;

    for(int i=1;i<=N;i++)
        cin>>temp[i];

    while(M--){
        int A, B, C;
        cin>>A>>B>>C;
        V[A].push_back({B,C});
    }

    for(int i=1;i<=N;i++){
        Dijkstra(i);
        menor=min(menor,dist[i]);
    }

    cout<<menor<<endl;

    return 0;
}
