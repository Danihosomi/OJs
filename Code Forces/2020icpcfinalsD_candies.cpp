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

int n;
int a;
int amount[1000005];

int main(){_
 
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> a;
        amount[a]++;
    }
    for (int i = 0; i <= 1000000; i++) 
        if (amount[i] > 1) {
            amount[i + 1] += amount[i] / 2;
            amount[i] = amount[i] & 1;
        }
    int counter = 0;
    for (int i = 0; i <= 1000000; i++)
        counter += amount[i];
 
    cout << (counter == 2 || (counter == 1 && n != 1) ? "Y" : "N") << '\n';
 
    return 0;
}