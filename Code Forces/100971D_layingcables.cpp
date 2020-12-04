#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
#define vi vector<int>
#define ii pair<int,int>

int N, i, P;
ll A;
vector < pair<ll,ll> >V;
vector<ll> F;
vector< pair<ll,ll> > R;
stack< pair<ll,ll> > S;
map<ll,ll> M;

int main(){_
    cin>>N;
    R.push_back(make_pair(0,0));
    V.resize(200010);
    F.resize(200010);

    for(i=1;i<=N;i++){
        cin>>A>>P;
        R.push_back(make_pair(A,P));
        M[A]=i;
    }
    sort(R.begin(),R.end());

    for(i=1;i<=R.size();i++){
        ll A=R[i].second;

        if(!S.empty()){
            while(A>S.top().second){
                V[M[S.top().first]].first=M[R[i].first];
                V[M[S.top().first]].second=abs(R[i].first-S.top().first);
                F[M[S.top().first]]=A;
                S.pop();
                if(S.empty())
                    break;
            }
        }

        S.push(make_pair(R[i].first,A));
    }

    while(!S.empty()){
        S.pop();
    }

    for(i=R.size();i>0;i--){
        ll A=R[i].second;

        if(!S.empty()){
            while(A>S.top().second){
                if(V[M[S.top().first]].first==0){
                    V[M[S.top().first]].first=M[R[i].first];
                    V[M[S.top().first]].second=abs(R[i].first-S.top().first);
                    F[M[S.top().first]]=A;
                }
                else{
                    if(V[M[S.top().first]].second>abs(R[i].first-S.top().first)){
                        V[M[S.top().first]].first=M[R[i].first];
                        V[M[S.top().first]].second=abs(R[i].first-S.top().first);
                    }
                    else if(V[M[S.top().first]].second==abs(R[i].first-S.top().first)){
                        if(F[M[S.top().first]]<A){
                            V[M[S.top().first]].first=M[R[i].first];
                            V[M[S.top().first]].second=abs(R[i].first-S.top().first);
                            F[M[S.top().first]]=A;
                        }
                    }
                }
                S.pop();
                if(S.empty())
                    break;
            }
        }

        S.push(make_pair(R[i].first,A));
    }




    for(i=1;i<=N;i++){
        if(V[i].first!=0)
            cout<<V[i].first<<" ";
        else
            cout<<-1<<" ";

    }
    cout<<endl;

    return 0;

}
