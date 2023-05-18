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

ll a, b, d;
vector<ll> ans1, ans2;
 
int main(){_
    cin >> a >> b;
 
    if (a % b) {
        cout << '\n';
        return 0;
    }
 
    d = a / b;
 
    for (ll i = 1; i * i <= d; i++) 
        if (d % i == 0) {
            ans1.push_back(i * b);
            if (i * i != d) ans2.push_back(b * (d / i));
        }
    
 
    for (ll item : ans1) 
        cout << item << ' ';
    
    for (int i = ans2.size() - 1; i >= 0; i--)
        cout << ans2[i] << ' ';
    
    cout << '\n';
 
    return 0;
}