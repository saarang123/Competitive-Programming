#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 502, K = 12, C = 1e5 + 2;
int a[C], f[C], h[K];
int dp[N][N * K];
//dp[i][j] - max amount for i people with j occurences of their _same_ favorite card
//can be solved individually for each card cuz h[i] is same for all
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int x, _ = 0; _ < n * k; _++)
    	cin >> x, a[x]++;
    for(int x, _ = 0; _ < n; _++)
    	cin >> x, f[x]++;
    for(int _ = 1; _ <= k; _++)
    	cin >> h[_];
    for(int i = 1; i <= n; i++)
    	for(int j = 0; j <= n * k; j++)
    		for(int c = 0; c <= min(j, k); c++)
    			dp[i][j] = max(dp[i][j], dp[i - 1][j - c] + h[c]);
    int ans = 0;
    for(int i = 1; i < C; i++)
    	if(f[i])
    		ans += dp[f[i]][a[i]];
    cout << ans << '\n';
    return 0;
}