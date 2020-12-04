#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>

int N, C, M, i, j;
char S;

int main(){_
    cin>>N;
    S=(char)(92);
    while(N--){
        vi V[210];
        cin>>M>>C;
        for(i=0;i<C;i++){
            int A;
            cin>>A;
            V[A%M].push_back(A);
        }
        for(i=0;i<M;i++){
            cout<<i<<" -> ";
            for(j=0;j<V[i].size();j++){
                cout<<V[i][j]<<" -> ";
            }
            cout<<S<<endl;
        }
        if(N>0)
        cout<<endl;
    }

    return 0;

}
