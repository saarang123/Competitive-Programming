#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int g = 0;
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++) g = __gcd(g, a[i] - a[i - 1]);
    for(int i = 0; i < m; i++) cout << __gcd(g, a[0] + b[i]) << ' ';
    cout << '\n';
    return 0;
}
