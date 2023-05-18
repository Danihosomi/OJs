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
vector<ll> numeros(2 * n);
vector<ll> res(2 * n);

int main(){_
    cin >> n;

    ll total = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> numeros[i];
        total += numeros[i];
    }

    sort(numeros.begin(), numeros.end());
    ll minimo = LONG_LONG_MAX;
    do {
        ll curr_max = 0;
        ll curr_sum = 0;
        for (int i = 0; i < n; i++) 
            curr_sum += numeros[i];
        curr_max = max(curr_max, max(curr_sum, total - curr_sum));
        for (int i = 1; i < n; i++) {
            curr_sum += numeros[n + i - 1] - numeros[i - 1];
            curr_max = max(curr_max, max(curr_sum, total - curr_sum));
        }
        if (curr_max < minimo) {
            for (int i = 0; i < 2 * n; i++) 
                res[i] = numeros[i];
            minimo = curr_max;
        }
    } while (next_permutation(numeros.begin() + 1, numeros.end()));

    for (ll item : res) 
        cout << item << ' ';
    
    cout << '\n';

    return 0;
}