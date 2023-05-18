#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>


int main(){_
    int N, M, i, soma=0;
    cin>>N>>M;
    vector< pair<int,int> > V;
    for(i=1;i<=N;i++){
        soma=0;
        for(int j=0;j<M;j++){
            int A;
            cin>>A;
            soma+=A;
        }
        V.push_back(make_pair(soma,i));
    }

    sort(V.begin(),V.end());

    for(i=0;i<3;i++){
        cout<<V[i].second<<endl;
    }

    return 0;

}

