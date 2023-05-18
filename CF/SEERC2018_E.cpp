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

int n, m, l;

vector<int> maxi;
vector<int> mini;

int main(){_

    int t = 1;
    //cin>>t;

    while(t--){
        cin >> n >> m >> l;        

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (y > l) continue;

            maxi.pb(x - y + l);
            mini.pb(x + y - l);
        }
        sort(all(maxi));
        sort(mini.rbegin(), mini.rend());

        n = maxi.size();

        for (int i = 0; i < m; i++) {
            int x;
            int ans = n;
            cin >> x;
            int start = -1, end = n;
            while (start + 1 != end) {
                int mid = (start + end) / 2;

                if (maxi[mid] >= x) 
                    end = mid;
                else
                    start = mid;
            }
            ans -= end;
            start = -1, end = n;
            while (start + 1 != end) {
                int mid = (start + end) / 2;

                if (mini[mid] <= x) 
                    end = mid;
                else
                    start = mid;
            }
            ans -= end;

            cout << ans << '\n';
        }
    }

    return 0;

}