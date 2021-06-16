#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lsb(x) ((x)&(-x))
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mk(x,y) make_pair(x,y)
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

int L, C;
int M[3005][3005], dp[3][3005][3005];

int ans(int last,int i,int j){
    if(i<=0 || i>L || j<=0 || j>C)
        return -INF;

    if(i==L && j==C)
        return M[i][j];
    
    if(dp[last][i][j]!=-1)
        return dp[last][i][j];
    
    int resp=0;
    if(!last){
        resp=M[i][j]+max(ans(1,i,j+1),ans(2,i,j-1));
        resp=max(resp,M[i][j]+ans(0,i+1,j));
    }
    if(last==1)
        resp=M[i][j]+max(ans(1,i,j+1),ans(0,i+1,j));

    if(last==2)
        resp=M[i][j]+max(ans(2,i,j-1),ans(0,i+1,j));


    return dp[last][i][j]=resp;
}

int main(){_
    cin>>L>>C;

    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=L;i++)
        for(int j=1;j<=C;j++)
            cin>>M[i][j];
    
    cout<<ans(0,1,1)<<'\n';

    return 0;
}