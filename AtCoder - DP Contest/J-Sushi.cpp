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

int n, see[305][305][305], v[4];
double dp[305][305][305];

double ans(int q1,int q2,int q3){
    if(q1+q2+q3==0) return 1;
    if(see[q1][q2][q3]) return dp[q1][q2][q3];
    see[q1][q2][q3]=1; 
    double resp=0, num=((double)(n-q1-q2-q3)/(double)n); num=(num/(1-num)); resp=num;
    if(q1) resp=(resp+ans(q1-1,q2,q3)*(double)((double)q1/(double)(q1+q2+q3)));
    if(q2) resp=(resp+ans(q1+1,q2-1,q3)*(double)((double)q2/(double)(q1+q2+q3)));
    if(q3) resp=(resp+ans(q1,q2+1,q3-1)*(double)((double)q3/(double)(q1+q2+q3)));
    return dp[q1][q2][q3]=resp;
}

int main(){_
    cin>>n;
    for(int i=1;i<=n;i++){
        int a; cin>>a; v[a]++;
    }
    cout.precision(9); cout.setf(ios::fixed);
    cout<<ans(v[1],v[2],v[3])+v[1]+2*v[2]+3*v[3]-1<<'\n';

    return 0;
}