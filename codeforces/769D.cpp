#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 2;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> f(N);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
    }
    int ans = 0;
    if(k == 0) {
        for(int i = 0; i < N; i++) ans += (f[i] * (f[i] - 1)) / 2;
    } else {
        for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++) if(__builtin_popcount(i ^ j) == k)
            ans += (f[i] * f[j]);
    }
    cout << ans << '\n';
    return 0;
}
