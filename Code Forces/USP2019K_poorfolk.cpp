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

int N;
ll V[500005], sum;

int main(){_
    cin>>N;

    for(int i=0;i<N;i++)
        cin>>V[i];

    sort(V,V+N);

    if(V[0]>1){
        cout<<1<<'\n';
        return 0;
    }
    sum=1;
    for(int i=1;i<N;i++){
        if(V[i]>sum+1){
            cout<<sum+1<<'\n';
            return 0;
        }
        sum+=V[i];
    }

    cout<<sum+1<<'\n';

    return 0;
}