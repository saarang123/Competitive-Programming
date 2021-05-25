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
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;

    auto check = [&] (ld x) {
    	ld res = 0;
    	for(int i = 0; i < n; i++)
    		if(ld(a[i]) / b[i] > x)
    			res += pow((ld) a[i] - x * b[i], 2);
    	return res;
    };
    ld l = -1001, r = 1001;
    ld eps = 1e-8;
    ld ans = 1e16;
    for(int _ = 0; _ < 40; _++) {
    	ld m = (l + r) / 2;
    	ld c = check(m), p = check(m - eps), q = check(m + eps);
    	ans = min({ans, c, p, q});
    	if(p <= c)
    		l = m;
    	else 
    		r = m;
    }
    cout << ans << '\n';
}
