#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string S, C;
set<string> K;
set<string, greater<string> > Y;
set<string>::iterator it, it1;

int main(){_
    int N, i;
    cin>>N;
    getline(cin, S);
    while(N--){
        K.clear();
        Y.clear();
        getline(cin, S);
        C="";
        for(i=0;i<S.size();i++){
            if(S[i]!=' ' && i!=S.size()-1){
                C+=S[i];
            }
            else{
                if(i!=S.size()-1){
                    K.insert(C);
                    Y.insert(C);
                    C="";

                }
                else{
                    C+=S[S.size()-1];
                    K.insert(C);
                    Y.insert(C);
                }

            }
        }
        it1=Y.begin();
        for(it=K.begin();it!=K.end();it++){
            if((*it)!=(*it1))
                cout<<(*it)<<" ";
            else
                cout<<(*it);
        }

        cout<<endl;
    }


    return 0;
}

