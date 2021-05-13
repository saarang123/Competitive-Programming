#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 5002;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, a; cin >> n >> a;
    vector<int> v(n), dp(n + 1);
    for(int &x : v) cin >> x;
    reverse(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		dp[i + 1] = v[i];
		if(i - a >= 0)
			dp[i + 1] += dp[i - a];
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}