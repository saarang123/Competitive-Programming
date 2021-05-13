#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a)
    	cin >> x;
    long long ans = 0;
    for(int i = 1; i < n; i++) {
    	ans += max(0, a[i - 1] - a[i]);
    	a[i] = max(a[i - 1], a[i]);
    }
    cout << ans << '\n';
    return 0;
}