#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

queue<int> Q;
int N, i;
vector<int> V;

int main(){_
    while(cin>>N && N!=0){
        queue<int> Q;
        for(i=1;i<=N;i++){
            Q.push(i);
        }
        while(Q.size()!=1){
            V.push_back(Q.front());
            Q.pop();
            i=Q.front();
            Q.pop();
            Q.push(i);
        }

        cout<<"Discarded cards:";
        for(i=0;i<V.size();i++){
            if(i!=V.size()-1)
                cout<<" "<<V[i]<<",";
            else{
                cout<<" "<<V[i]<<endl;
            }
        }
        cout<<"Remaining card: "<<Q.front()<<endl;
        V.clear();

    }

    return 0;

}

