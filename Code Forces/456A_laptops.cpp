#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>
#define pii pair<int,int>

int func(pii A, pii B){
    return A.second<B.second;
}

int main(){_
    int N, i;
    cin>>N;
    vector< pair<int,int> > V, S;

    for(i=0;i<N;i++){
        int A, B;
        cin>>A>>B;
        V.push_back(make_pair(A,B));
        S.push_back(make_pair(A,B));
    }

    sort(V.begin(),V.end());
    sort(S.begin(),S.end(), func);

    for(i=0;i<N;i++){
        if(V[i].first!=S[i].first){
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }

    cout<<"Poor Alex"<<endl;

    return 0;

}
