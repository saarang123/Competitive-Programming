#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1003, C = 7;
const int inf = 1e10;
int dp[N][N][10], a[N][3];

int remax(const &int x, const &int y) {
	return x = max(x, y);
}

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
    for(int i = 1; i <= n; i++)
    	for(int j = 0; j < 3; j++)
    		cin >> a[i][j];
    for(int i = 0; i <= n; i++) 
    	for(int j = 0; j <= m; j++)
    		for(int k = 0; k < C; k++)
    			dp[i][j][k] = -inf;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
    	for(int j = 0; j < C; j++) dp[i][0][j] = dp[i - 1][0][j];
    	for(int j = 1; j <= k; j++) {
    		dp[i][j][0] = max(a[i][0] + a[i][1] + dp[i - 1][j - 1][3], a[i][1] + a[i][2] + dp[i - 1][j - 1][1]);
    		if(i > 1) {
    			dp[i][j][0]
    		}
    	}
    }
    return 0;
}