#include <bits/stdc++.h>
using namespace std;
const int SQRTN = 710, MXN = 500 * 1000;
int dp[SQRTN][SQRTN], a[MXN + 1];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int q; cin >> q;
    while(q--) {
    	int t, x, y;
    	cin >> t >> x >> y;
    	if(t == 1) {
    		a[x] += y;
    		for(int i = 1; i < SQRTN; i++)
    			dp[i][x % i] += y;
    	} else {
    		if(x < SQRTN)
    			cout << dp[x][y] << '\n';
    		else {
    			int ans = 0;
    			for(int i = y; i <= MXN; i += x)
    				ans += a[i];
    			cout << ans << '\n';
    		}
    	}
    }
    return 0;
}