#include <bits/stdc++.h>
using namespace std;
const int MXN = 3003;
const int mod = 1e9 + 7;
int dp[MXN][MXN], qt[MXN][MXN], a[MXN], n;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    for(int i = 1; i <= n; i++) {
    	qt[i][i] = a[i];
    	for(int j = i + 1; j <= n; j++) {
    		qt[i][j] = min(qt[i][j - 1], a[j]);
    		qt[j][i] = qt[i][j];
    	}
    }
    for(int i = 1; i <= n; i++)
    	dp[1][i] = dp[1][i - 1] + (qt[1][i] == a[i]);
    for(int i = 2; i <= n; i++)
    	for(int j = 1; j <= n; j++) {
    		dp[i][j] = dp[i][j - 1] + (qt[i][j] == a[j]) * dp[i - 1][j];
    		if(dp[i][j] >= mod)
    			dp[i][j] -= mod;
    	}
    cout << dp[n][n] << '\n';
    return 0;
}