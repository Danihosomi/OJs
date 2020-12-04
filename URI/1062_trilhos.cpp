#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int N, i, k, H;

int main(){_

    while(true){
        cin>>N;
        if(N==0)
            break;

        while(true){
            stack<int> A;

            for(i=N;i>=1;i--)
                A.push(i);

            stack<int> S;
            k=0;
            bool ok=false;
            for(i=0;i<N;i++){
                cin>>H;
                if(H==0)
                    break;

                ok=false;

                if(!A.empty()){
                    if(A.top()==H){
                        A.pop();
                        k++;
                        ok=true;
                    }
                }
                if(!S.empty()){
                    if(S.top()==H){
                        S.pop();
                        k++;
                        ok=true;
                    }
                }
                if(!A.empty() && !ok){
                    while(A.top()!=H){
                        S.push(A.top());
                        A.pop();
                        if(A.empty())
                            break;
                    }
                }
                if(!A.empty()){
                    if(A.top()==H){
                        A.pop();
                        k++;
                        ok=true;
                    }
                }
                if(!S.empty()){
                    if(S.top()==H){
                        S.pop();
                        k++;
                    }
                }
            }
            if(H==0)
                break;

            if(k==N)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }

    return 0;

}
