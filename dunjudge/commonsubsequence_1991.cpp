#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 2003;
int a[N], b[N], dp[N][N];
int n, m;

int f(int i, int j) {
	if(i < 1 || j < 1)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 0;
	if(a[i] == b[j])
		(dp[i][j] += 1 + f(i - 1, j - 1)) %= mod;
	(dp[i][j] += f(i - 1, j)) %= mod;
	(dp[i][j] += f(i, j - 1)) %= mod;
	(dp[i][j] -= f(i - 1, j - 1) - mod) %= mod;
	return dp[i][j];
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
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    for(int i = 1; i <= m; i++)
    	cin >> b[i];
    cout << (1 + f(n, m)) % mod << '\n';
    return 0;
}