#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 300 * 1000 + 4;
std::mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());
const ll mod1 = 4838493294837;
const ll mod2 = 2848385849322415;
ll p[mxn], s[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	if(u > v) swap(u, v);
    	ll r = rng() % mod1;
    	(p[u] += r) %= mod2;
    	p[v] = (p[v] - r + mod1) % mod1;
    	r = rng() % mod2;
    	(s[u] += r) %= mod2;
    	s[v] = (s[v] - r + mod2) % mod2;
    }
    map<array<ll, 2>, int> cnt;
    ll ans = 0, l = 0, r = 0;
    cnt[{0, 0}]++;
    for(int i = 0; i < n; i++) {
    	(l += p[i]) %= mod1;
    	(r += s[i]) %= mod2;
    	ans += cnt[{l, r}];
    	cnt[{l, r}]++;
    }
    cout << ans << '\n';
    return 0;
}