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

string c, rc;
int atualx, atualy, last, tam;
vector<ii> ans;

int main(){_
    int t = 1;
    //cin>>t;
    while(t--){
    }

    cin>>c; rc=c; reverse(all(rc));
    string start=""; last=-1;

    for(int i=0;i<min(sz(rc),3);i++) start+=rc[i];
    if(start[sz(start)-1]==start[sz(start)-2] || (sz(start)>=3 && (start=="LRL" || start=="RLR" || start=="UDU" || start=="DUD"))){
        cout<<"impossible"<<'\n'; return 0;
    }

    for(auto m : c){
        if(m=='L' || m=='R'){
            int x=(m=='L' ? 0 : 1);
            if(last!=x^1){
                tam+=2;
                ans.pb({atualx+tam,atualy});
                ans.pb({atualx-tam,atualy});
            }
            atualx=(m=='L' ? ans.back().f+1 : ans[sz(ans)-2].f-1);
            atualy=ans.back().s;
            last=(m=='L' ? 0 : 1);
        }
        else{
            int x=(m=='U' ? 2 : 3);
            if(last!=x^1){
                tam+=2;
                ans.pb({atualx,atualy+tam});
                ans.pb({atualx,atualy-tam});
            }
            atualx=ans.back().f;
            atualy=(m=='D' ? ans.back().s+1 : ans[sz(ans)-2].s-1);
            last=(m=='U' ? 2 : 3);
        }
    }


    return 0;

}