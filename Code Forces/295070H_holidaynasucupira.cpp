#include <bits/stdc++.h>
#define INF 1e14
#define ii pair<long long,long long>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x) & (-x))
using namespace std;
typedef long long int ll;

ll N, M;
ll dist[10005];
set< pair<ll, ii> > S;
vector< ii > V[10005];
vector< ii > last[10005];
priority_queue< ii, vector< ii >, greater< ii > > P;

void Dijkstra(){
    for(int i=0;i<=N;i++)
        dist[i]=INF;

    dist[1]=0;
    P.push({0,1});

    while(!P.empty()){
        ll X, D;
        D=P.top().first;
        X=P.top().second;
        P.pop();

        if(D>dist[X]) continue;

        for(int i=0;i<V[X].size();i++){
            ll Y, d, k;
            Y=V[X][i].first;
            d=V[X][i].second;
            k=d;
            d+=D;
            if(dist[Y]>d && !S.count({Y,{X,k}})){
                last[Y].clear();
                last[Y].push_back({X,k});
                dist[Y]=d;
                P.push({d,Y});
            }
            else if(dist[Y]==d && !S.count({Y,{X,k}})){
                last[Y].push_back({X,k});
            }
        }
    }
}

void func(int A){
    if(A!=1){
        for(int i=0;i<last[A].size();i++){
            int Y=last[A][i].first;
            ll d=last[A][i].second;
            S.insert({A,{Y,d}});
            func(Y);
        }
    }
}

int main(){_
    cin>>N>>M;

    while(M--){
        int A, B, C;
        cin>>A>>B>>C;
        V[A].push_back({B,C});
        V[B].push_back({A,C});
    }

    Dijkstra();
    func(N);
    Dijkstra();

    if(dist[N]!=INF)
        cout<<dist[N]<<endl;
    else
        cout<<-1<<endl;


	return 0;
}


