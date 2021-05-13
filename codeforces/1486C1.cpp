#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

map<array<int, 2>, int> cnt;
int mx;

int qry(int l, int r) {
	if(l == r) return -1;
	if(cnt[{l, r}])
		return cnt[{l, r}];
	cout << "? " << l << ' ' << r << '\n';
	cout.flush();
	int x; cin >> x;
	cnt[{l, r}] = x;
	return x;
}

int fix(int l, int r) {
	if(l == r)
		return l;
	//cout << "in fix: " << l << ' ' << r << endl;
	int m = (l + r) >> 1;
	if(mx > m) {
		int x = qry(m + 1, r);
		if(x == mx)
			return fix(m + 1, r);
		mx = qry(l, m);
		return fix(l, m);
	} else {
		int x = qry(l, m);
		if(x == mx)
			return fix(l, m);
		mx = qry(m + 1, r);
		return fix(m + 1, r);
	}
}

void solve_case() {
    int n; cin >> n;
	int l = 1, r = n;
	mx = qry(l, r);
	int x = fix(1, n);
	cout << "! " << x << '\n';
	cout.flush();
}
