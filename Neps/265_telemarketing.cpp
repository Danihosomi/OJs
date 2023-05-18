#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>
#define vii vector< pair<int,int> >

priority_queue< pair<int,int>, vii, greater< pair<int,int> > > P;
vi S;
int N, i, K, inter , id, soma;

int main(){_
    cin>>N>>K;
    S.resize(N+1);
    for(i=1;i<=N;i++)
        P.push(make_pair(0,i));


    for(i=0;i<K;i++){
        cin>>inter;
        soma=0;
        id=P.top().second;
        soma+=inter;
        soma+=P.top().first;
        P.pop();
        S[id]++;
        P.push(make_pair(soma, id));
    }



    for(i=0;i<N;i++){
        cout<<i+1<<" "<<S[i+1]<<endl;
    }

    return 0;

}
