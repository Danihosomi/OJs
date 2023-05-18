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
#define sz(x) (int)x.size()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const ll mod=1e9+7;
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);

int N, K, ini, qtd, psa[200005], maior;

int main(){_
    cin>>N>>K;
    
    for(int i=0;i<N;i++){
        int A, B; cin>>A>>B;
        maior=max(A+B+1,maior);
        psa[A]++;
        psa[A+B+1]--;
    }
    for(int i=1;i<=maior;i++)
        psa[i]+=psa[i-1];
    qtd=INF;
    for(int i=0;i<=480;i++){
        int sum=0;
        for(int j=0;;j++){
            if(j*K+i>maior)
                break;
            sum+=psa[j*K+i];
        }
        if(sum<qtd){
            qtd=sum;
            ini=i;
        }
    }

    cout<<ini<<' '<<qtd<<'\n';
    


    return 0;
}