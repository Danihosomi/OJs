#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define R(x) ((x<<1)+1)
#define L(x) (x<<1)
#define f first
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;

const ll mod = 1e9 + 7;

int n;
ll cap, v[1000005], psa[1000005];
string c;

int func(int x){
    for(int i=0;i<=n-x;i++)
        if(psa[x+i]-psa[i]>cap)
            return 1;

    return 0;
}

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }

    cin>>n>>c;

    for(int i=1;i<=n;i++){
        cin>>v[i];
        psa[i]=psa[i-1]+v[i];
    }

    for(int i=0;i<sz(c)-1;i++){
        cap*=10;
        cap+=(c[i]-'0');
    }

    if(c.back()=='G') cap*=1024;
    else if(c.back()=='T') cap*=(1024*1024);

    if(psa[n]<=cap){
        cout<<n<<' '<<-1<<'\n';
        return 0;
    }


    int ini, meio, fim;
    ini=1; fim=n;

    while(ini<fim){
        meio=ini+((fim-ini)>>1);
        if(func(meio)) fim=meio;
        else ini=meio+1;
    }
    
    cout<<ini-1<<' ';
    for(int i=0;i<=n-ini;i++){
        if(psa[ini+i]-psa[i]>cap){
            cout<<i+1<<'\n';
            return 0;
        }
    }

    cout<<-1<<'\n';

    return 0;

}