#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ll int

int N, i, M;
vector<ll> V;
map<ll, ll> S;
ll A, B;

int main(){_
    while(cin>>N>>M){
    V = vector<ll> (N+1);
    S.clear();
    for(i=1;i<=N;i++){
        cin>>V[i];
        S[V[i]]++;
    }

    ll soma=0, j;

    for(i=0;i<M;i++){
        cin>>A>>B;
        soma=0;
        if(S.find(B)!=S.end() && S[B]>=A){
            for(j=1;j<=N;j++){
                if(V[j]==B){
                    soma++;
                    if(soma==A){
                        cout<<j<<endl;
                        break;
                    }
                }
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    }

    return 0;

}
