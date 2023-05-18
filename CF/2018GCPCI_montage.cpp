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

int  N, V[1005], H[1005];

int func(int A){
    for(int i=0;i<N;i++){
        if(V[i]>H[i]+A)
            return 0;
        else if(H[i]+A>V[i])
            return 1;
    }
    return 1;
}

int main(){_
    cin>>N;

    for(int i=0;i<N;i++)
        cin>>H[i];
    for(int i=0;i<N;i++)
        cin>>V[i];
    
    int l, meio, r;
    l=0;
    r=1000;
    while(l<r){
        meio=l+((r-l)>>1);
        if(func(meio)) r=meio;
        else l=meio+1;
    }    

    cout<<l<<'\n';

    return 0;
}