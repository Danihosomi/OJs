#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll N, i;
ll resp=0, A;
vector<ll> V, R, R1;

int main(){_
    while(cin>>N){
        if(N==0)
            break;

        resp=0;
        stack< pair<ll, ll> > S;
        V.clear();
        V.push_back(0);
        R.resize(N+2);
        R1.resize(N+2);

        for(i=1;i<=N;i++){
            cin>>A;
            V.push_back(A);

            if(!S.empty()){
                while(S.top().second>A){
                    R[S.top().first]=i;
                    S.pop();
                    if(S.empty())
                        break;
                }
            }
            S.push(make_pair(i,A));
        }

        while(!S.empty()){
            R[S.top().first]=N+1;
            S.pop();
            if(S.empty())
                break;
        }

        for(i=N;i>0;i--){
            A=V[i];

            if(!S.empty()){
                while(S.top().second>=A){
                    R1[S.top().first]=i+1;
                    S.pop();
                    if(S.empty())
                        break;
                }
            }

            S.push(make_pair(i,A));
        }

        while(!S.empty()){
            R1[S.top().first]=1;
            S.pop();
            if(S.empty())
                break;
        }



        for(i=1;i<=N;i++){
            resp=max(abs(V[i]*(R[i]-R1[i])),resp);
        }

        cout<<resp<<endl;
    }


    return 0;

}
