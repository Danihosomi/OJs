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

int N, K, M[455][455], dp[455][455], ans;

int main(){_
    cin>>N>>K;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            cin>>M[i][j];
            dp[i][j]=(M[i][j]!=0);
        }

    
    for(int k=1;k<=N;k++){
        if(M[k][k]){
            cout<<'*'<<'\n';
            return 0;
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++){
                if(i==k || j==k) continue;
                if(M[i][j]>M[i][k]+M[k][j]){
                    cout<<'*'<<'\n';
                    return 0;           
                }
                else if(M[i][j]==M[i][k]+M[k][j])
                    dp[i][j]=0;
            }
    }

    for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++){
            ans+=K*dp[i][j];
            if(M[i][j]!=M[j][i]){
                cout<<'*'<<'\n';
                return 0;
            }
        }

    cout<<ans<<'\n';

    return 0;
}