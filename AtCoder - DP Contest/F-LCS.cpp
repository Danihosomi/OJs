#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
#define inf (int)1e9
#define linf (ll)1e17
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;

int dp[3005][3005];
ii save[3005][3005];
string a, b, ans;

int main(){_
    cin>>a>>b;

    for(int i=1;i<=sz(a);i++)
        for(int j=1;j<=sz(b);j++){
            if(a[i-1]==b[j-1]){
                if(dp[i][j]<1+dp[i-1][j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    save[i][j]={i-1,j-1};
                }
            }
            else{
                if(dp[i][j]<dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    save[i][j]={i,j-1};
                }
                if(dp[i][j]<dp[i-1][j]){
                    dp[i][j]=dp[i-1][j];
                    save[i][j]={i-1,j};
                }

            }
        }

    ii id={sz(a),sz(b)};
    while(id.f!=0 || id.s!=0){
        if(a[id.f-1]==b[id.s-1]) ans+=a[id.f-1];
        id=save[id.f][id.s];
    }
    reverse(all(ans));
    cout<<ans<<'\n';

    return 0;
}