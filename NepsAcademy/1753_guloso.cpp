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
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int N, M, V1[3005], V2[105], dp[3005][105][105][2];

int ans(int id,int l,int r,int ok){
    if(l>r && id>N)
        return 0;

    if(~dp[id][l][r][ok])
        return dp[id][l][r][ok];

    int resp=0;
    if(id<=N){
        if(ok)
            resp=max(resp,V1[id]+ans(id+1,l,r,0));
        else{
            resp=max(resp,ans(id+1,l,r,ok));
            resp=max(resp,ans(id+1,l,r,1));
        }
    }
    if(l<=r){
        if(!ok){
            resp=max(resp,ans(id,l+1,r,0));
            resp=max(resp,ans(id,l,r-1,0));    
            resp=max(resp,ans(id,l+1,r,1));
            resp=max(resp,ans(id,l,r-1,1));        
        }
        else{
            resp=max(resp,V2[l]+ans(id,l+1,r,0));
            resp=max(resp,V2[r]+ans(id,l,r-1,0));    
        }
    }

    return dp[id][l][r][ok]=resp;
}

int main(){_
    cin>>N;
    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=N;i++)
        cin>>V1[i];

    cin>>M;
    for(int i=1;i<=M;i++)
        cin>>V2[i];

    sort(V2+1,V2+1+M);

    cout<<max(ans(1,1,M,1),ans(1,1,M,0))<<'\n';

    return 0;
}