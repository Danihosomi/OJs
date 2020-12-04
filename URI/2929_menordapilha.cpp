#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int N, i;
stack<int> K;
string C;
int G;

int main(){_
    cin>>N;
    bool ok=true;
    while(N--){
        cin>>C;
        if(C[1]=='U'){
            cin>>G;
            if(!K.empty()){
                i=min(G,K.top());
                K.push(i);
            }
            else
                K.push(G);
        }

        else if(C[1]=='I'){
            if(K.empty())
                cout<<"EMPTY"<<endl;

            else{
                cout<<K.top()<<endl;
            }
        }

        else{
            if(!K.empty()){
                K.pop();
            }
            else{
                cout<<"EMPTY"<<endl;
            }
        }
    }

    return 0;

}
