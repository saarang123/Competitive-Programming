#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> nxt;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	nxt[a[i]] = max(i, nxt[a[i]]);
    }
    long long ans = 1;
    int m = 0;
    for(int i = 0; i < n; i++) {
    	if(m < i)
    		ans = (ans * 2LL) % mod;
    	m = max(m, nxt[a[i]]);
    }
    cout << ans << '\n';
    return 0;
}