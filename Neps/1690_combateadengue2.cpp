#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define f first
#define s second
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define ii pair<double,double>
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

int N, M, see[5][16][32768];
double dp[5][16][32768];
vector<ii> V;

double dist(ii A,ii B){
    return hypot(A.f-B.f,A.s-B.s);
}

double ans(int id,int place,int mask){
    if(id==M)
        return INF;
    
    if(mask==(1<<N+M)-(1<<M))
        return dist(V[id],V[place]);

    if(see[id][place][mask])
        return dp[id][place][mask];

    double resp=INF;
    resp=min(resp,dist(V[id],V[place])+ans(id+1,id+1,mask));
    for(int i=M;i<N+M;i++)
        if(!(mask&(1<<i)))
            resp=min(resp,dist(V[place],V[i])+ans(id,i,(mask|(1<<i))));

    see[id][place][mask]=1;    
    return dp[id][place][mask]=resp;
}

int main(){_
    cin>>N>>M;

    for(int i=0;i<N+M;i++){
        double A, B; cin>>A>>B;
        V.push_back({A,B});
    }

    cout.precision(2);
    cout.setf(ios::fixed);
    cout<<ans(0,0,0)<<'\n';

    return 0;
}