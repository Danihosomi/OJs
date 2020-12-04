#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000007
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

ll mod= MOD;

ll N, i, j;

int main(){_
    cin>>N;
    ll A, B, med;
    while(N--){
        ll soma=0;
        queue<ll> Q;
        cin>>A>>B;

        if(B>=A){
        for(i=0;i<A;i++){
            Q.push(i);
            soma+=i;
        }
        Q.push(soma);
        j=A+1;

        while(j!=B){
            med=Q.front();
            Q.pop();
            soma=(2*soma-med+mod)%mod;
            Q.push(soma);
            j++;
        }


        cout<<soma<<endl;
        }
        else{
            cout<<(B-1)%mod<<endl;
        }
    }


    return 0;

}
