#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5002;
vector<array<int, 2>> cnt[N][N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, d;
    cin >> n >> d;
    vector<array<int, 4>> c(n);
    for(auto &[x, s, a, b] : c) {
    	cin >> x >> s >> a >> b;
    	s = min(s, (d + b - a) / b);
    }
    
    return 0;
}