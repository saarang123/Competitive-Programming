#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
const int K = 1002, M = 502;
int dp[2][M][K], a[M][M];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= m; j++)
    		cin >> a[i][j];
    for(int i = 0; i < 2; i++)
    	for(int j = 0; j <= m; j++)
    		for(int t = 0; t <= k; t++)
    			dp[i][j][t] = (t == 0 ? 0 : -inf);
    k--;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
    		if(i == 1 && j == 1) {
    			dp[i & 1][j][0] = a[i][j]; continue;
    		}
    		int l = 0, r = 0;
    		while(l + r <= k) {
    			if(i == 1) {
    				dp[i & 1][j][l + r] = a[i][j] + dp[i & 1][j - 1][r];
    				r++;
    			}
    			else if(j == 1) {
    				dp[i & 1][j][l + r] = a[i][j] + dp[(i & 1) ^ 1][j][l];
    				l++;
    			}
    			else if(dp[(i & 1) ^ 1][j][l] > dp[i & 1][j - 1][r]) {
    				dp[i & 1][j][l + r] = a[i][j] + dp[(i & 1) ^ 1][j][l];
    				l++;
    			}
    			else {
    				dp[i & 1][j][l + r] = a[i][j] + dp[i & 1][j - 1][r];
    				r++;
    			}
    		}
    	}
    }
    cout << dp[n & 1][m][k] << '\n';
    return 0;
}