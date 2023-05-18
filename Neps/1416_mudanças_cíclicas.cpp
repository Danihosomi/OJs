#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

string A, B;
set<string> S;

int main(){_
    cin>>A>>B;
    
    for(int i=0;i<B.size();i++){
        string aux="";
        for(int j=i;j<i+B.size();j++)
            aux+=B[j%B.size()];
        S.insert(aux);
    }

    for(int i=0;i<A.size();i++){
        if(i+B.size()>A.size())
            break;
        string aux="";
        for(int j=i;j<i+B.size();j++)
            aux+=A[j];
        if(S.count(aux)){
            cout<<"yes"<<'\n';
            return 0;
        }
    }

    cout<<"no"<<'\n';

    return 0;
}