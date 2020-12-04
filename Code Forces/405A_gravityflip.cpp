#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>


int main(){_
    int N, i;
    vi V;
    cin>>N;
    for(i=0;i<N;i++){
        int A;
        cin>>A;
        V.push_back(A);
    }

    sort(V.begin(),V.end());

    for(i=0;i<N;i++)
        cout<<V[i]<<" ";

    cout<<endl;

    return 0;

}
