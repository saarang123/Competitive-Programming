#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    	freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
	#endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int &x : h)
    	cin >> x;
    auto check = [&] (int x, array<int, 2> c) {
    	if(c[0] + k <= x && c[1] + k <= x) return true;
    	if(x + k <= c[0] && x + k <= c[1]) return true;
    	return false;
    };
    vector<array<int, 2>> dp(n);
    dp[0] = {h[0], h[0]};
    for(int i = 1; i < n; i++) {
    	int mn = dp[i - 1][0] - k + 1;
    	if(mn < h[i]) mn = h[i];
    	if(mn > h[i] + k - 1) mn = h[i] + k - 1;
    	int mx = dp[i - 1][1] + k - 1;
    	if(mx < h[i]) mx = h[i];
    	if(mx > h[i] + k - 1) mx = h[i] + k - 1;
    	if(check(mn, dp[i - 1]) && check(mx, dp[i - 1])) return void(cout << "NO\n");
    	dp[i] = {mn, mx};
    }
    //for(int i = 0; i < n; i++) cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    if(dp[n - 1][0] <= h[n - 1] && h[n - 1] <= dp[n - 1][1]) cout << "YES\n";
    else cout << "NO\n";
}
