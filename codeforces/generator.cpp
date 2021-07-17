#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7, C = 100, M = 1000;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("in.txt", "w", stdout);
    int n = 20;
    int x = rng() % C, y = rng() % C;
    cout << n << ' ' << x << ' ' << y << '\n';
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        int p = rng() % M;
        a[i] = p;
    }
    sort(a.begin(), a.end());
    for(int p : a)
        cout << p << ' ';
    cout << '\n';
    cout << '\n';
    return 0;
}