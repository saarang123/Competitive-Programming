#include <bits/stdc++.h>
using namespace std;
const int mxn = 52;
int n, m;
long long a[mxn];

bool check(long long mask) {
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
	dp[0][0] = true;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			for(int k = 0; k < i; k++)
				if((mask & (a[i] - a[k])) == mask && dp[k][j - 1])
					dp[i][j] = true;
	return dp[n][m];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	a[i] += a[i - 1];
    }
    long long ans = 0;
    for(int bit = 56; bit >= 0; bit--) {
    	if(check(ans ^ (1LL << bit)))
    		ans ^= (1LL << bit);
    }
    cout << ans << '\n';
    return 0;
}