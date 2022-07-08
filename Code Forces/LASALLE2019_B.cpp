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
 
char m[16][16];
int vis[16][16], vis1[2][200], maxidp, maxido;
int varx[]={0,0,1,-1};
int vary[]={1,-1,0,0};
priority_queue<pair<int,ii>, vector<pair<int,ii>>,greater<pair<int,ii>> > q;
vector<ii> qtd[2][200];
queue<ii> ans, ans1;
 
void bfs(int inix,int iniy){
    q.push({(m[inix][iniy]=='P' ? maxidp : maxido),{inix,iniy}}); (m[inix][iniy]=='P' ? maxidp++ : maxido++);
    vis[inix][iniy]=1;
 
    while(!q.empty()){
        int x, y, id;
        id=q.top().f; x=q.top().s.f; y=q.top().s.s; q.pop();
        qtd[(m[inix][iniy]=='P' ? 0 : 1)][id].pb({x,y});
 
        for(int i=0;i<4;i++){
            int nx, ny;
            nx=x+varx[i];
            ny=y+vary[i];
            if(nx>=1 && nx<=14 && ny>=1 && ny<=14 && m[nx][ny]==m[inix][iniy] && !vis[nx][ny]){ 
                vis[nx][ny]=1;
                q.push({id,{nx,ny}});
            }
        }
    }
}
 
int main(){_
 
    for(int i=1;i<=14;i++)
        for(int j=1;j<=14;j++)
            cin>>m[i][j];
 
    bfs(5,5);
    bfs(10,10);
 
    for(int i=1;i<=14;i++)
        for(int j=1;j<=14;j++)
            if(m[i][j]!='.' && !vis[i][j]) bfs(i,j);
 
    cout<<maxidp+maxido<<'\n';
 
    ans.push({0,0});
    ans1.push({1,0});
    vis1[0][0]=1;
    vis1[1][0]=1;
    
    for(int i=0;i<maxidp+maxido;i++){
        int x, y;
        if(i%2==0){
            if(!ans.empty()){
                x=ans.front().f; y=ans.front().s; ans.pop();
                cout<<"P "<<sz(qtd[x][y])<<' ';
                for(auto k : qtd[x][y])
                    cout<<k.f<<' '<<k.s<<' ';
                cout<<'\n';
            }
            else{
                x=ans1.front().f; y=ans1.front().s; ans1.pop();
                cout<<"O "<<sz(qtd[x][y])<<' ';
                for(auto k : qtd[x][y])
                    cout<<k.f<<' '<<k.s<<' ';
                cout<<'\n';
            }
        }
        else{
            if(!ans1.empty()){
                x=ans1.front().f; y=ans1.front().s; ans1.pop();
                cout<<"O "<<sz(qtd[x][y])<<' ';
                for(auto k : qtd[x][y])
                    cout<<k.f<<' '<<k.s<<' ';
                cout<<'\n';
            }
            else{
                x=ans.front().f; y=ans.front().s; ans.pop();
                cout<<"P "<<sz(qtd[x][y])<<' ';
                for(auto k : qtd[x][y])
                    cout<<k.f<<' '<<k.s<<' ';
                cout<<'\n';
            }
        }
 
        for(auto k : qtd[x][y]){
            for(int j=0;j<(!x ? maxidp : maxido);j++){
                if(vis1[x][j]) continue;
                for(auto k1 : qtd[x][j]){
                    if((k.f==k1.f+1 && k.s==k1.s+1) || (k.f==k1.f-1 && k.s==k1.s+1) || (k.f==k1.f+1 && k.s==k1.s-1) || (k.f==k1.f-1 && k.s==k1.s-1)){
                        if(!x){
                            ans.push({0,j});
                            vis1[0][j]=1;
                        }
                        else{
                            ans1.push({1,j});
                            vis1[1][j]=1;
                        }
                        break;
                    }
                }
            }
        }
    }
    
 
    return 0;
}