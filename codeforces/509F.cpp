#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int mxn = 502;
long long dp[mxn][mxn];
int a[mxn];
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
    for(int i = 1; i <= n + 1; i++)
    	dp[i][i - 1] = 1;
    for(int i = n; i; i--) {
    	for(int j = i; j <= n; j++) {
    		dp[i][j] = dp[i + 1][j];
    		for(int k = i + 1; k <= j; k++) {
    			if(a[k] > a[i])
    				(dp[i][j] += (dp[i + 1][k - 1] * dp[k][j])) %= mod;
    		}
    	}
    }
    cout << dp[2][n] << '\n';
    return 0;
}