#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1), bit(32);
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[n] = 1;
    auto fill = [&] (int i) {
    	for(int b = 0; b < 32; b++) if(a[i] >> b & 1) (bit[b] += dp[i]) %= mod;
    };
    fill(n);
    for(int i = n - 1; i; i--) {
    	for(int j = 0; j < 32; j++)
    		if(a[i] >> j & 1)
    			(dp[i] += bit[j]) %= mod;
    	fill(i);
    }
    cout << dp[1] << '\n';
    return 0;
}