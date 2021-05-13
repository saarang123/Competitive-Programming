#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> c(n);
    for(int &x : c)
        cin >> x;
    sort(c.begin(), c.end());
    auto check = [&] (int m) {
        int total = k * l, need = m;
        for(int i = n - 1; i >= 0 && need > 0 && total >= 0; i--, need--) {
            if(c[i] >= m) continue;
            if(m - c[i] > k)
                return false;
            total -= (m - c[i]);
        }
        return need <= 0 && total >= 0;
    };
    int mn = 0, mx = n;
    while(mn < mx) {
        int mid = (mn + mx + 1) >> 1;
        if(check(mid))
            mn = mid;
        else
            mx = mid - 1;
    }
    cout << mn << '\n';
    return 0;
}