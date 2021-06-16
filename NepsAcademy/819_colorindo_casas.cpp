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

bool ok1;
vector<int> V[100010];
int N, A, B, B1, A1;
vector<int> C;

void dfs(int K){
    int i;

    for(i=0;i<V[K].size();i++){
        int D;
        D=V[K][i];
        if(C[D]!=0){
            if(C[D]==C[K]){
                ok1=false;
                break;
            }
        }
        else{
            if(C[K]==1){
                C[D]=2;
                B1++;
                dfs(D);
            }
            else{
                C[D]=1;
                A1++;
                dfs(D);
            }
        }
    }
    return;
}


int main(){_

    cin>>N;
    C.resize(N+1);
    ok1=true;
    int i;

    for(i=1;i<N;i++){
        cin>>A>>B;
        V[A].push_back(B);
        V[B].push_back(A);
    }

    C[1]=1;
    A1++;
    dfs(1);

    if(ok1 && A1==B1)
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;

    return 0;

}