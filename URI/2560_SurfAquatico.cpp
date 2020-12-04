#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<int,int> >
#define ii pair<int, int>
typedef long long ll;

int N, M, A, i, S, k;
ll soma, soma1;
vector<int> V;

int main(){_

    while(cin>>N>>M){
        priority_queue< ii, vii, greater< ii > > P;
        priority_queue< ii > Q;
        V.clear();
        V.push_back(0);
        soma=0;
        soma1=0;
        k=0;
        for(i=1;i<=N;i++){
            cin>>A;
            V.push_back(A);
            P.push(make_pair(A, i));
            Q.push(make_pair(A, i));
            soma+=A;
            if(i>=M){
                soma-=V[k];
                soma1+=soma;
                while(i-M>=P.top().second){
                    P.pop();
                }
                while(i-M>=Q.top().second){
                    Q.pop();
                }
                soma1-=P.top().first;
                soma1-=Q.top().first;
                k++;
            }
        }

        cout<<soma1<<endl;
    }

    return 0;

}
