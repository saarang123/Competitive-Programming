#include <bits/stdc++.h>
using namespace std;
const int mxn = 2002, lgn = 45;
long long y[mxn], p[mxn];
int n, a, b;

bool check(long long mask) {
	vector<int> dp(n + 1, n + 1);
	dp[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			if((mask | (p[i] - p[j])) == mask)
				dp[i] = min(dp[i], dp[j] + 1);
	return dp[n] <= b;
}

bool fix(long long mask) {
	vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));
	dp[0][0] = true;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= i; j++)
			for(int k = 0; k < i; k++) 
				if(dp[k][j - 1] && (mask | (p[i] - p[k])) == mask)
					dp[i][j] = true;
	for(int i = a; i <= b; i++)
		if(dp[n][i])
			return true;
	return false;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
    	cin >> y[i];
    for(int i = 1; i <= n; i++)
    	p[i] = p[i - 1] + y[i];
    long long ans = (1LL << lgn) - 1;
    for(int bit = lgn - 1; bit >= 0; bit--) {
    	if(a == 1) {
    		if(check(ans ^ (1LL << bit)))
    			ans ^= (1LL << bit);
    	}
    	else {
    		if(fix(ans ^ (1LL << bit)))
    			ans ^= (1LL << bit);
    	}
    }
    cout << ans << '\n';
    return 0;
}