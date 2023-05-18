#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int inf = (int)1e9;
const ll mod = 1e9 + 7;
const ll linf = (ll)1e17;

int n;
ll dp[65550], m[20][20];
 
int main(){_ 
    cin>>n;
 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>m[i][j];
 
    for(int i=1;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
                if((i&(1<<j)) && (i&(1<<k))) dp[i]+=m[j][k];

    // Submask Enumeration in O(3^n)
    for(int i=0;i<(1<<n);i++){
        for(int sub=i;sub;sub=((sub-1)&i)){
            dp[i] = max(dp[i],dp[sub]+dp[i^sub]);
        }
    }

    cout<<dp[(1<<n)-1]<<'\n';
 
    return 0;
}