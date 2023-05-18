#include <bits/stdc++.h>
#define INF 1e9
#define ii pair<int,pair<int,int> >
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

int N, vis[10005];
vector<int> V[10005];
queue<int> Q;

int main(){
    cin>>N;

    for(int i=0;i<N;i++){
        int A, B;
        cin>>A>>B;
        V[A].push_back(B);
    }

    Q.push(1);

    while(!Q.empty()){
        int X;
        X=Q.front();
        Q.pop();

        for(int i=0;i<V[X].size();i++){
            int Y=V[X][i];
            if(!vis[Y]){
                vis[Y]=1+vis[X];
                Q.push(Y);
            }
        }
    }

    if(vis[1]==N)
        cout<<"S"<<endl;
    else
        cout<<"N"<<endl;

    return 0;
}
