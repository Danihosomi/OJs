#include <iostream>
#include <stack>
using namespace std;

int main(){
    int A, i, j=0, mht;
    bool gg=true;
    string X;
    cin>>A;

    while(j<A){
        stack<char> S;
        gg=true;
        cin>>X;

        for(i=0;i<X.size();i++){
            if(X[i]=='(' || X[i]=='{' || X[i]=='['){
                S.push(X[i]);
            }

            else{
                if(S.empty()){
                    gg=false;
                    break;
                }
                else{
                    mht=S.top();
                    S.pop();

                    if((X[i] == ')' && mht != '(') || (X[i] == ']' && mht != '[') || (X[i] == '}' && mht != '{') ) {
                    gg=false;
                    break;
                    }
                }
            }
        }

        if(!S.empty()){
            gg=false;
        }

        if(gg==true)
            cout<<"S"<<endl;

        else
            cout<<"N"<<endl;

        j++;
    }

    return 0;

}
