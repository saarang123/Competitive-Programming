#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<array<int, 2>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i][0];
    for(int i = 1; i <= n; i++) cin >> a[i][1];
    sort(a.begin(), a.end());
	vector<int> dp(n + 1);
	dp[1] = 1;
	int ans = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[j][1] < a[i][1] && a[j][0] < a[i][0])
				dp[i] = max(dp[i], 1 + dp[j]);
		ans += (dp[i] == 1);
	}
	//for(int i = 1; i <= n; i++) cout << a[i][0] << ' ' << a[i][1] << '\n';
	//for(int i = 1; i <= n; i++) cout << dp[i] << ' '; cout << '\n';
	cout << ans << '\n';
    return 0;
}