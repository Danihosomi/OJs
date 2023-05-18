#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

ll N, C, i, resp, soma, ini, temp;
priority_queue<ll, vector<ll>, greater<ll> > V;

int main(){_
    cin>>C>>N;

    for(i=0;i<C;i++)
        V.push(0);

    for(i=0;i<N;i++){
        cin>>ini>>temp;
        soma=V.top();
        V.pop();
        if(soma<=ini){
            soma=ini+temp;
            V.push(soma);
        }
        else{
            if(soma-ini>20){
                soma+=temp;
                V.push(soma);
                resp++;
            }
            else{
                soma+=temp;
                V.push(soma);
            }
        }

    }

    cout<<resp<<endl;

    return 0;

}
