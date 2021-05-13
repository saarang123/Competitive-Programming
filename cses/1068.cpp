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
    long long n; cin >> n;
    while(n != 1) {
    	cout << n << ' ';
    	if(n & 1)
    		n = 3 * n + 1;
    	else
    		n /= 2;
    }
    cout << 1 << '\n';
    return 0;
}