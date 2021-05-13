#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
int dp[N][N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    a.resize(unique(a.begin(), a.end()) - a.begin());
	n = a.size();
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] == a[j])
				dp[i][j] = 1 + dp[i + 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[0][n - 1] << '\n';
    return 0;
}