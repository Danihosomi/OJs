#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;
 
int n;
vi v, v1;
 
int func(int x){
    int last=0;
 
    for(auto y : v){
        if(y<=x) continue;
        if(!last) last=y;
        else{
            if(y!=last) return 0;
            last=0;
        }
    }
    if(last) return 0;
 
    for(auto y : v1){
        if(y<=x) continue;
        if(!last) last=y;
        else{
            if(y!=last) return 0;
            last=0;
        }
    }
 
    return (!last);
}
 
int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }
 
    cin>>n;
 
    for(int i=0;i<n;i++){
        int a; cin>>a; v.pb(a);
    }
    for(int i=0;i<n;i++){
        int a; cin>>a; v1.pb(a);
    }
 
    int ini=0, meio, fim=1e9+1;
    while(ini<fim){
        meio=ini+((fim-ini)>>1);
        if(func(meio)) fim=meio;
        else ini=meio+1;
    }
 
    cout<<ini<<'\n';
 
    return 0;
}