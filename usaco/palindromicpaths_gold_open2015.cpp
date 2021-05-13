#include <bits/stdc++.h>
using namespace std;
void usaco(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
const int mod = 1e9 + 7;
const int N = 502;
int dp[N][N][N / 2];
char a[N][N];
int n, m;

int dt(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }
bool out(int x, int y) { return x < 1 || x > y; }

int f(int x1, int x2, int y1) {
	if(dp[x1][x2][y1] != -1) return dp[x1][x2][y1];
	int moves = (x1 - 1) + (y1 - 1);
	int y2 = m - (moves - (n - x2));
	if(x1 > x2 || y1 > y2) return 0;
	if(out(x1, n) || out(x2, n) || out(y1, m) || out(y2, m)) return 0;
	if(dt(x1, y1, x2, y2) <= 1) return dp[x1][x2][y1] = 1;
	dp[x1][x2][y1] = 0;
	if(a[x1 + 1][y1] == a[x2 - 1][y2]) (dp[x1][x2][y1] += f(x1 + 1, x2 - 1, y1)) %= mod;
	if(a[x1][y1 + 1] == a[x2 - 1][y2]) (dp[x1][x2][y1] += f(x1, x2 - 1, y1 + 1)) %= mod;
	if(a[x1 + 1][y1] == a[x2][y2 - 1]) (dp[x1][x2][y1] += f(x1 + 1, x2, y1)) %= mod;
	if(a[x1][y1 + 1] == a[x2][y2 - 1]) (dp[x1][x2][y1] += f(x1, x2, y1 + 1)) %= mod;
	return dp[x1][x2][y1];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    usaco("palpath");
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n;
    m = n;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++)
    		cin >> a[i][j];
    }
    cout << (a[1][1] == a[n][m] ? f(1, n, 1) : 0) << '\n';
    return 0;
}