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

int n, see[3005][3005];
double v[3005], dp[3005][3005];

double ans(int id,int qtd){
    if(id==n) return (qtd*2>n);
    if(see[id][qtd]) return dp[id][qtd];
    see[id][qtd]=1;
    return dp[id][qtd]=(v[id]*ans(id+1,qtd+1)+(1-v[id])*ans(id+1,qtd));
}   

int main(){_
    cin>>n; for(int i=0;i<n;i++) cin>>v[i];
    cout.precision(9); cout.setf(ios::fixed);
    cout<<ans(0,0)<<'\n';
    return 0;
}