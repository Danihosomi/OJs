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

int l, c, ans, m[505][505];

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }

    cin>>l>>c;

    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            char a; cin>>a;
            m[i][j]=(a=='#');
        }
    }

    for(int i=2;i<=l-1;i++){
        for(int j=2;j<=c-1;j++){
            ans+=(!m[i][j]);
        }
    }

    if(l<=2 || c<=2){
        if(l==1){
            for(int i=2;i<=c-1;i++)
                ans+=(!m[1][i]);
        }
        if(c==1){
            for(int i=2;i<=l-1;i++)
                ans+=(!m[i][1]);
        }
        if(l==2){
            for(int i=2;i<=c-1;i++)
                ans+=(!m[1][i] && !m[2][i]);
        }
        if(c==2){
            for(int i=2;i<=l-1;i++)
                ans+=(!m[i][1] && !m[i][2]);
        }
    }
    else{
        int ok=1;
        for(int i=2;i<=c-1;i++)
            if(m[1][i] || m[l][i]) ok=0;
        for(int i=2;i<=l-1;i++)
            if(m[i][1] || m[i][c]) ok=0;

        ans+=ok;
    }


    cout<<ans<<'\n';

    return 0;

}