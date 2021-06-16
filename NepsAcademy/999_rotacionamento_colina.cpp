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

int N, M, R, V1[100005], V2[100005];

int main(){_
    cin>>N>>M>>R;

    for(int i=1;i<=N;i++){
        int A; cin>>A;
        V2[A]++;
    }

    for(int i=M;i>=1;i--){
        V2[i]+=V2[i+1];
        V1[V2[i]]++;
    }
    
    for(int i=N;i>=1;i--)
        V1[i]+=V1[i+1];

    if(R%2){
        for(int i=1;i<=M;i++)
            cout<<V2[i]<<' ';
        cout<<'\n';
    }
    else{
        for(int i=1;i<=N;i++)
            cout<<V1[i]<<' ';
        cout<<'\n';
    }

    return 0;
}