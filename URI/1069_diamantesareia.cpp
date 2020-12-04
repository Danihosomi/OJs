#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int N;
string S;

int main(){_
    cin>>N;
    int i;
    while(N--){
        stack<char> C;
        cin>>S;
        int resp=0;
        for(i=0;i<S.size();i++){
            if(S[i]=='<')
                C.push(S[i]);
            else if(S[i]=='>'){
                if(!C.empty()){
                    C.pop();
                    resp++;
                }
            }
        }
        cout<<resp<<endl;
    }


    return 0;

}
