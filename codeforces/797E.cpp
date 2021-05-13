#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3;
const int sqn = 320;
int dp[sqn][mxn], a[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    int x = sqrt(n);
    for(int i = 1; i * i <= n; i++) 
    	for(int j = n; j; j--) {
    		if(j + a[j] + i > n)
    			dp[i][j] = 1;
    		else
    			dp[i][j] = 1 + dp[i][j + a[j] + i];
    	}
    int q; cin >> q;
    while(q--) {
    	int p, k;
    	cin >> p >> k;
    	if(k <= x)
    		cout << dp[k][p] << '\n';
    	else {
    		int ans = 0;
    		while(p <= n) {
    			ans++;
    			p = p + a[p] + k;
    		}
    		cout << ans << '\n';
    	}
    }
    return 0;
}