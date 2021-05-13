#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

vector<int> primes;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    for(int i = 2; i < 1e5 + 2; i++) {
    	bool ok = 1;
    	for(int j = 2; j * j <= i; j++) {
    		if(i % j == 0) {
    			ok = 0; break;
    		}
    	}
    	if(ok) primes.push_back(i);
    }
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int d; cin >> d;
    int x = *lower_bound(all(primes), 1 + d);
    int y = *lower_bound(all(primes), x + d);
    long long ans = x * y;
    cout << ans << '\n';
}
