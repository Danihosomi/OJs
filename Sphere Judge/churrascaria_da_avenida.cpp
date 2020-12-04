#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
#define ii pair<ll,ll>
typedef long long ll;

priority_queue< ii , vii, greater< ii > > P;
vector<ll> V;
ll N, K, i, S;

int  main(){_
    ll A;
    while(cin>>N>>K && N!=0 && K!=0){
        priority_queue< ii , vii, greater< ii > > P;
        V.clear();

        for(i=1;i<=N;i++){
            cin>>A;
            P.push(make_pair(A,i));

            if(i>=K){
                S=P.top().second;
                while(S<=(i-K)){
                        P.pop();
                        S=P.top().second;
                }
                S=P.top().first;
                V.push_back(S);
            }
        }

        for(i=0;i<V.size();i++){
            if(i!=V.size()-1)
                cout<<V[i]<<" ";
            else
                cout<<V[i]<<endl;
        }

    }


    return 0;

}
