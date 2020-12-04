#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int N, i;
string C;
set<string> K;


int main(){_
    while(cin>>N && N!=0){
        K.clear();

        for(i=0;i<N;i++){
            cin>>C;
            sort(C.begin(),C.end());

            K.insert(C);
        }

        cout<<K.size()<<endl;

    }

    return 0;

}
