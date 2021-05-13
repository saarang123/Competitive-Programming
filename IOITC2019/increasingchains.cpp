#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
const int mxn = 5002;
int nxt[mxn][mxn], a[mxn], n, k;
int dp[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    for(int i = 1; i <= n; i++) {
    	vector<int> lis;
    	for(int j = i; j <= n; j++) {
    		int pos = upper_bound(lis.begin(), lis.end(), a[j]) - lis.begin();
    		if(pos == lis.size()) lis.push_back(a[j]);
    		else lis[pos] = a[j];
    		nxt[i][j] = lis.size();
    	}
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= i; j++) 
    		if(nxt[j][i] >= k)
    				dp[i] = max(dp[i], dp[j - 1] + nxt[j][i]);
    	dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n] << '\n';
    return 0;
}