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
#define sz(x) (long long)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.txt", "r", stdin);

int varx[]={1,1,1,0,0,0,-1,-1,-1};
int vary[]={-1,0,1,0,1,-1,1,0,-1};
int L, C, M[105][105], ans[105][105];

int verifica(int maxi,int maxj){
    for(int i=maxi-1;i<=L+1;i++){
        for(int j=maxj-1;j<=C+1;j++){
            int sum=0;
            for(int k=0;k<9;k++){
                int X, Y;
                X=i+varx[k];
                Y=j+vary[k];
                if(X<1 || Y<1 || X>L || Y>C) continue;
                if(ans[X][Y]==-1)
                    return 1;
                sum+=ans[X][Y];
                if(sum>M[i][j])
                    return 0;
            }
            if(sum<M[i][j])
                return 0;
        }
    }
    return 1;
}

int solve(int i,int j){
    if(i==L+1)
        return verifica(i,j);

    int nexti, nextj;
    nexti=i; nextj=j+1;
    if(nextj>C){
        nextj=1;
        nexti++;
    }

    ans[i][j]=0;
    if(verifica(i,j) && solve(nexti,nextj))
        return 1;
    ans[i][j]=1;
    if(verifica(i,j) && solve(nexti,nextj))
        return 1;
    
    ans[i][j]=-1;
    return 0;
}

int main(){_
    cin>>L>>C;

    for(int i=0;i<=L+1;i++)
        for(int j=0;j<=C+1;j++)
            cin>>M[i][j];

    memset(ans,-1,sizeof(ans));
    if(solve(1,1))
        for(int i=1;i<=L;i++){
            for(int j=1;j<=C;j++)
                cout<<(ans[i][j] ? 'X' : '.');
            cout<<'\n';
        }
    else
        cout<<"impossible"<<'\n';

    return 0;
}