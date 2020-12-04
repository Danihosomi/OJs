#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>

map<string, double> M;
int N, i, K, P;
double resp;
string S;

int main(){_
    cin>>N;

    while(N--){
        resp=0;
        M.clear();
        cin>>K;
        for(i=0;i<K;i++){
            cin>>S>>resp;
            M[S]=resp;
        }
        cin>>P;
        resp=0;
        for(i=0;i<P;i++){
            cin>>S>>K;
            resp+=K*M[S];
        }
        cout.precision(2);
        cout.setf(ios::fixed);
        cout<<"R$ "<<resp<<endl;
    }


    return 0;

}


