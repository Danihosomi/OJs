#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<int,int>
#define INF 1e9+1
#define BUG(x) cout<<x<<endl;
#define bug cout<<"oi"<<endl;
#define all(x) x.begin(),x.end()
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

ll F[100], N;
set<ll> S;
vi V;

int back(ll X){
    if(X==1)
        return 1;

    if(S.count(X))
        return 0;
    
    for(int i=72;i>=1;i--){
        if(X%F[i]) continue;
        V.eb(i);
        if(back(X/F[i])) return 1;
        V.pop_back();
    }
    
    S.insert(X);
    return 0;
}

int main(){_
    F[1]=2;
    F[2]=3;
    for(int i=3;;i++){
        F[i]=F[i-1]+F[i-2];
        if(F[i]>1e15)
            break;
    }

    cin>>N;

    if(back(N)){
        for(auto v : V){
            for(int i=0;i<v;i++)
                cout<<'A';
            cout<<'B';
        }
        cout<<'\n';
    }

    else
        cout<<"IMPOSSIBLE"<<'\n';


    return 0;
}