#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
int dp[N][2];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    dp[1][0] = dp[1][1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i][1] = i - 1;
        for(int j = 1; j < i; j++) {
            dp[i][0] = min(dp[i][0], 1 + max(dp[i - j][0], dp[j][0]));
            dp[i][1] = min(dp[i][1], 1 + max(max(dp[i - j][1], dp[j][1]), dp[i - j][0] + dp[j][0]));
        }
    }
    cout << (dp[n][1] <= q ? "YES" : "NO") << '\n';
    return 0;
}