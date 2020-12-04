#include <bits/stdc++.h>
#define INF 1e9
#define ii pair<int,int>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

int N, M, dist[550], ini, fim, memo[550][550];
vector< ii > V[550];
vector<int> last[550];
priority_queue< ii, vector< ii >, greater< ii > > P;

void Dijkstra(){
    for(int i=0;i<=N;i++)
        dist[i]=INF;

    dist[ini]=0;
    P.push({0,ini});

    while(!P.empty()){
        int X, D;
        D=P.top().first;
        X=P.top().second;
        P.pop();

        if(D>dist[X]) continue;

        for(int i=0;i<V[X].size();i++){
            int Y, d;
            Y=V[X][i].first;
            d=V[X][i].second;
            d+=D;
            if(dist[Y]>d && !memo[Y][X]){
                last[Y].clear();
                last[Y].push_back(X);
                dist[Y]=d;
                P.push({d,Y});
            }
            else if(dist[Y]==d && !memo[Y][X]){
                last[Y].push_back(X);
            }
        }
    }
}

void func(int A){
    if(A!=ini){
        for(int i=0;i<last[A].size();i++){
            int Y=last[A][i];
            memo[A][Y]=1;
            func(Y);
        }
    }
}

int main(){_

    while(cin>>N>>M && N){

        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                memo[i][j]=0;
            }
        }

        for(int i=0;i<=N;i++)
            V[i].clear();

        cin>>ini>>fim;

        while(M--){
            int A, B, C;
            cin>>A>>B>>C;
            V[A].push_back({B,C});
        }

        Dijkstra();
        func(fim);
        Dijkstra();

        if(dist[fim]!=INF)
            cout<<dist[fim]<<endl;
        else
            cout<<-1<<endl;
    }

	return 0;
}
