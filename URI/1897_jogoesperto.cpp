#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int N, M;
queue<ll> Q;
map<ll, ll> F;

int main(){_
    cin>>N>>M;
    Q.push(N);
    F[N]=0;

    ll S1, S2, S3, S4, S5, S6, S;
    while(true){
        if(Q.empty())
            break;
        S=Q.front();
        Q.pop();

        S1=S*2;
        S2=S*3;
        S3=S/2;
        S4=S/3;
        S5=S+7;
        S6=S-7;

        if(F[S1]==0 && S1!=N){
            Q.push(S1);
            F[S1]=F[S]+1;
            if(S1==M)
                break;
        }
        if(F[S2]==0 && S2!=N){
            Q.push(S2);
            F[S2]=F[S]+1;
            if(S2==M)
                break;
        }
        if(F[S3]==0 && S3!=N){
            Q.push(S3);
            F[S3]=F[S]+1;
            if(S3==M)
                break;
        }
        if(F[S4]==0 && S4!=N){
            Q.push(S4);
            F[S4]=F[S]+1;
            if(S4==M)
                break;
        }
        if(F[S5]==0 && S5!=N){
            Q.push(S5);
            F[S5]=F[S]+1;
            if(S5==M)
                break;
        }
        if(F[S6]==0 && S6!=N){
            Q.push(S6);
            F[S6]=F[S]+1;
            if(S6==M)
                break;
        }
    }

    cout<<F[M]<<endl;

    return 0;

}
