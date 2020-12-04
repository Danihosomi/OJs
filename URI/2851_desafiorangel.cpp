#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int N, i, A, V[100010];
stack< pair<int,int> > S;

int main(){_

    cin>>N;

    for(i=0;i<N;i++){
        cin>>A;

        if(!S.empty() && A>S.top().first){
            while(A>S.top().first){
                V[S.top().second]=A;
                S.pop();
                if(S.empty())
                    break;
            }
        }

        S.push(make_pair(A,i));
    }

    for(i=0;i<N;i++){
        if(V[i]!=0)
            cout<<V[i]<<" ";
        else{
            if(i==N-1)
                cout<<"*"<<endl;
            else
                cout<<"* ";
        }
    }


    return 0;

}
