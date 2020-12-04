#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
typedef long long int ll;

const ll mod=1e9+7;
int N;
int E[1000010], D[1000010];
ll dp[1000010], see[1000010];
vector< pair<int,int> > V;
stack< pair<int,int> > S;

ll ans(int i){
    if(E[i]==0 && D[i]==0){
        see[i]=1;
        return dp[i]=1;
    }
    if(see[i]) return dp[i];
    see[i]=1;

    ll resp;
    resp=0;
    if(D[i]!=0){
        resp=(resp+ans(D[i]))%mod;
    }
    if(E[i]!=0){
        resp=(resp+ans(E[i]))%mod;
    }

    dp[i]=resp;

    return dp[i];

}


int main(){_
    int i;
    ll A, B;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>A>>B;
        V.push_back(make_pair(B,A));
    }

    sort(V.begin(),V.end());

    for(i=0;i<N;i++){
        A=V[i].second;

        if(!S.empty()){
            while(S.top().second<A){
                D[S.top().first]=i+1;
                S.pop();
                if(S.empty())
                    break;
            }
        }

        S.push(make_pair(i+1,A));
    }

    while(!S.empty()){
        S.pop();
    }

    for(i=N-1;i>=0;i--){
        A=V[i].second;

        if(!S.empty()){
            while(S.top().second<A){
                E[S.top().first]=i+1;
                S.pop();
                if(S.empty())
                    break;
            }
        }

        S.push(make_pair(i+1,A));
    }

    ll resp;
    resp=0;
    for(i=1;i<=N;i++){
        resp=(resp+ans(i))%mod;
    }

    cout<<resp<<endl;

    return 0;
}

