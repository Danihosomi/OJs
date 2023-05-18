#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define vii vector< pair<long long,long long> >
typedef long long ll;

int N, M, V[500000];
set< pair<int,int> > S;
set< pair<int,int> >::iterator it;

int main(){_
    cin>>N>>M;
    int A, i;

    for(i=0;i<M;i++)
        S.insert(make_pair(0,i));

    while(N--){
        cin>>A;
        S.erase(make_pair(V[A%M],A%M));
        V[A%M]++;
        S.insert(make_pair(V[A%M],A%M));

        it=S.begin();

        cout<<M*(*it).first+(*it).second<<endl;
    }

    return 0;

}
