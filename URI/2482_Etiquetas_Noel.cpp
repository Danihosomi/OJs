#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>

map<string,string> S;
int N, M, i;
string nome, lingua, men;

int main(){_
    cin>>N;
    getline(cin, lingua);
    for(i=1;i<=2*N;i++){
        if(i%2!=0)
            getline(cin, lingua);

        else{
            getline(cin, men);
            S[lingua]=men;
        }
    }

    cin>>M;

    getline(cin, nome);
    for(i=1;i<=2*M;i++){
        if(i%2!=0)
            getline(cin, nome);

        else{
            getline(cin, lingua);
            cout<<nome<<endl<<S[lingua]<<endl<<endl;
        }
    }


    return 0;

}
