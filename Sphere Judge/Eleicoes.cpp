#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>

map<int, int> M;
map<int, int>::iterator it;
int N, i;

int main(){_
    cin>>N;
    while(N--){
        cin>>i;
        M[i]++;
    }
    int maior=0, id;
    for(it=M.begin(); it!=M.end();it++){
        i=it->second;
        N=it->first;
        if(i>maior){
            maior=i;
            id=N;
        }
    }

    cout<<id<<endl;

    return 0;

}
