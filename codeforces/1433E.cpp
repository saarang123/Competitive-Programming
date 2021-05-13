#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    int ans = 0;
    vector<int> f(n + 2);
    vector<bool> g(1 << 20, 0);
    f[0] = 1;
    for(i = 1; i <= n; i++) f[i] = i * f[i - 1];
    for(int mask = 0; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) != n/2) continue;
        int x = 0;
        for(i = 0; i < n; i++) if(!(mask & (1 << i))) x |= (1 << i);
        if(g[x] || g[mask]) continue;
        ans += (f[n / 2 - 1] * f[n / 2 - 1]);
        g[x] = g[mask] = true;
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
