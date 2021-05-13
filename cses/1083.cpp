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
    vector<bool> a(n);
    for(int x, i = 0; i < n - 1; i++) {
    	cin >> x; x--;
    	a[x] = true;
    }
    for(int i = 0; i < n; i++)
    	if(!a[i])
    		return cout << i + 1 << '\n', 0;
    return 0;
}