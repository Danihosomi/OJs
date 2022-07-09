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

int n, v[28], menor, num[28][1000005], tam[28];
ll sum[28], ans, id;
vector<pair<ll,int>> aux;

ll binpow(ll A,ll E){
    ll resp = 1;
    while(E){
        if(E&1) resp=(resp*A)%mod;
        
		A=(A*A)%mod;
        E>>=1;
    }
    return resp;
}

int compare(int a,int b){
    if(a==-1 || b==-1) return 1;
    if(tam[a]>tam[b]) return 1;
    if(tam[b]>tam[a]) return -1;
    
    for(int i=tam[a];i>=0;i--){
        if(num[a][i]>num[b][i]) return 1;
        if(num[b][i]>num[a][i]) return -1;
    }

    return 0;
}

int main(){_
    int t = 1;
    //cin>>t;
    //while(t--){
    //}

    while(cin>>n){
        cout<<"Case #"<<t<<": "; t++; id=1; ans=0; menor=-1;

        while(n--){
            string c; cin>>c; reverse(all(c));

            for(int i=0;i<sz(c);i++){
                if(i==sz(c)-1 && sz(c)>1) v[c[i]-'a']=1;
                num[c[i]-'a'][i]++; tam[c[i]-'a']=max(i,tam[c[i]-'a']);
                while(num[c[i]-'a'][i]>=26){
                    num[c[i]-'a'][i]-=26;
                    num[c[i]-'a'][i+1]++;
                    tam[c[i]-'a']=max(i+1,tam[c[i]-'a']);
                }
                sum[c[i]-'a']=(sum[c[i]-'a']+binpow(26,i))%mod;
            }

            for(char i='a';i<='z';i++){
                while(num[i-'a'][sz(c)]>=26){
                    num[i-'a'][sz(c)]-=26;
                    num[i-'a'][sz(c)+1]++;
                    tam[i-'a']=max(sz(c)+1,tam[i-'a']);
                }
            }
        }

        for(int i=0;i<=25;i++){
            if(!v[i] && compare(menor,i)>0) menor=i;
            aux.pb({sum[i],i});
        }

        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                if(compare(aux[i].s,aux[j].s)>0){
                    swap(aux[i],aux[j]);
                }
            }
        }
        
        for(auto x : aux){
            if(x.s==menor) continue;
            else{
                ans=(ans+(x.f*id)%mod)%mod;
                id++;
            }
        }

        cout<<ans<<'\n';
        for(int i=0;i<26;i++){ 
            tam[i]=v[i]=sum[i]=0;
            memset(num[i],0,sizeof(num[i]));
        }
        aux.clear();
    }

    return 0;
}