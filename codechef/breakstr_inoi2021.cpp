#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define all(x) x.begin(), x.end()
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	string ans = string(n, '0');
	vector<int> p(2 * n + 5, -1);
	int o = 0, ct = n + 1;
	for(int i = 0; i < n; i++) {
		o += (s[i] == '0' ? 1 : -1);
		if(p[o + ct] < 0)
			p[o + ct] = i + 1;
	}
	int i = n;
	string ans = string(n, '0');
}

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	#ifdef saarang
	freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
	freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
	#endif
	int tc; cin >> tc;
	while(tc--)
		solve();
}