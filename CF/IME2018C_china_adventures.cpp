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

int N, W, dist[19][19], dp[19][525288], resposta;
pair<int, ii > see[19][525288];
vector< vector<string> > V;

int ans(int id,int mask){
    if(mask==(1<<(N+1))-1)        
        return 0;
    if(dp[id][mask]!=-1)
        return dp[id][mask];
    int resp=INF;
    for(int i=1;i<=N;i++){
        if(!(mask&(1<<i))){
            int X=min(dist[id][i],W+dist[0][i])+ans(i,mask|(1<<i));
            if(resp>X){
                resp=X;
                if(dist[id][i]<dist[0][i]+W){
                    see[id][mask]=make_pair(0,make_pair(i,mask|(1<<i)));
                }
                else{
                    see[id][mask]=make_pair(1,make_pair(i,mask|(1<<i)));
                }
            }
        }
    }
    return dp[id][mask]=resp;
}

void func(int id,int mask){
    if(mask==(1<<(N+1))-1)
        return;
    if(see[id][mask].first==1)
        cout<<'*'<<'\n';
    cout<<see[id][mask].second.first<<'\n';
    func(see[id][mask].second.first,see[id][mask].second.second);
}

int main(){_
    cin>>N>>W;
    memset(dp,-1,sizeof(dp));
    
    V.resize(N+1);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=21;j++){
            string S;
            cin>>S;
            V[i].emplace_back(S);
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=0;k<21;k++){
                for(int h=0;h<21;h++){
                    if(V[i][k][h]!=V[j][k][h]){
                        dist[i][j]++;
                        dist[j][i]++;
                    }
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int k=0;k<21;k++){
            for(int h=0;h<21;h++){
                if(V[i][k][h]!='0'){
                    dist[i][0]++;
                    dist[0][i]++;
                }
            }
        }
    }

    cout<<ans(0,1)<<'\n';
    func(0,1);

    return 0;
}