#include <bits/stdc++.h>
using namespace std;
const int mxn = 5002;
const int mod = 1e9 + 7;
int dp[mxn][mxn];

int add(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	return a;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    for(int i = 0; i < mxn; i++)
    	for(int j = 0; j < mxn; j++) {
    		if(!i)
    			dp[i][j] = 1;
    		else if(!j)
    			dp[i][j] = 0;
    		else if(i == 1)
    			dp[i][j] = j;
    		else {
    			dp[i][j] = add(add(dp[i - 1][j], dp[i - 1][j]), dp[i][j - 1]);
    			dp[i][j] -= dp[i - 2][j];
    			if(dp[i][j] < 0)
    				dp[i][j] += mod;
    		}
    	}
    int q; cin >> q;
    while(q--) {
    	int n, m;
    	cin >> m >> n;
    	cout << dp[n][m] << '\n';
    }
    return 0;
}