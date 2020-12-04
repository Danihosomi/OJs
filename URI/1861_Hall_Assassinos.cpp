#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vi vector<int>

map<string, int> M;
map<string, int> morto;
map<string, int>::iterator it;
int i;

int main(){_
    string S, K;
    i=0;
    while(cin>>S>>K){
        M[S]++;
        morto[K]++;
    }

    cout<<"HALL OF MURDERERS"<<endl;

    for(it=M.begin();it!=M.end();it++){
        if(morto.find(it->first)==morto.end()){
            cout<<it->first<<" "<<it->second<<endl;
        }
    }

    return 0;

}
