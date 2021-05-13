#include <bits/stdc++.h>
using namespace std;

void usaco(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 52;
int dp[N][N][N][N], a[N];

int f(int i, int j, int mn, int mx) {
	if(mn > mx)
		return -N;
	if(i > j) return 0;
	if(dp[i][j][mn][mx] != -1)
		return dp[i][j][mn][mx];
	if(i == j) 
		return (mn <= a[i] && a[i] <= mx);
	remax(dp[i][j][mn][mx], f(i + 1, j - 1, mn, mx)); //swap and dont choose any
	if(a[j] >= mn)
		remax(dp[i][j][mn][mx], 1 + f(i + 1, j - 1, a[j], mx)); //swap and choose j
	if(a[i] <= mx)
		remax(dp[i][j][mn][mx], 1 + f(i + 1, j - 1, mn, a[i])); //swap and choose i
	if(mn <= a[j] && a[i] <= mx)
		remax(dp[i][j][mn][mx], 2 + f(i + 1, j - 1, a[j], a[i])); //swap and choose both
	remax(dp[i][j][mn][mx], f(i + 1, j, mn, mx));   //dont swap dont choose
	if(mn <= a[i])
		remax(dp[i][j][mn][mx], 1 + f(i + 1, j, a[i], mx)); //dont swap, choose i
	remax(dp[i][j][mn][mx], f(i, j - 1, mn, mx)); //dont swap dont choose
	if(a[j] <= mx)
		remax(dp[i][j][mn][mx], 1 + f(i, j - 1, mn, a[j])); //dont swap choose j
	return dp[i][j][mn][mx];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    usaco("subrev");
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << f(1, n, 1, 50) << '\n';
    return 0;
}