#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define lsb(x) ((x)&(-x))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int inf = (int)1e9;
const ll mod = 1e9 + 7;
const ll linf = (ll)1e18;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
	long long eval(long long x) const { return k * x + m; }
};

struct CHT {
	deque<Line> hull;
	static const ll LMAX = linf;

	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(Line &x, const Line &y) {
		if (x.k == y.k) x.p = x.m > y.m ? LMAX : -LMAX;
		else x.p = div(y.m - x.m, x.k - y.k);
		return x.p >= y.p;
	}
	void add(long long k, long long m) {
		Line L = {k, m, 0};
		while ((int) hull.size() >= 2 && (isect(L, hull.back()),isect(hull.back(), hull[(int) hull.size() - 2]), L.p < hull.back().p)) hull.pop_back();
		hull.push_back(L);
	}
	long long query(long long x) {
		while ((int) hull.size() >= 2 && hull[0].eval(x) >= hull[1].eval(x)) hull.pop_front(); // aqui define se quer max ou min
		return hull[0].eval(x);
	}
};

int n;
ll dp[200005], k;
vector<ll> h;
CHT hull;

int main(){_
    cin>>n>>k; dp[0]=0;

    for(int i=0;i<n;i++){
        int a; cin>>a; h.pb(a);
    } hull.add(-2*h[0],h[0]*h[0]);

    for(int i=1;i<n;i++){
        dp[i]=k+h[i]*h[i]+hull.query(h[i]);
        hull.add(-2*h[i],(dp[i]+h[i]*h[i]));
    }

    cout<<dp[n-1]<<'\n';

    return 0;
}