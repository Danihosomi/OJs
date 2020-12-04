#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>

int func(int A, int B){
    return A>B;
}

int main(){_
    int N, i;
    vi V, R;
    cin>>N;
    for(i=0;i<N;i++){
        int A;
        cin>>A;
        if(A%2==0)
            V.push_back(A);
        else
            R.push_back(A);
    }

    sort(V.begin(),V.end());
    sort(R.begin(),R.end(), func);

    for(i=0;i<V.size();i++)
        cout<<V[i]<<endl;
    for(i=0;i<R.size();i++)
        cout<<R[i]<<endl;

    return 0;

}
