#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("in.txt", "w", stdout);
    int n = 15000;
    cout << 1 << '\n' << n << '\n';
    for(int i = 0; i < n; i++) {
    	cout << rng() % 2;
    }
    return 0;
}