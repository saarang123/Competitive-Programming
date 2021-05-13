#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

const int N = 5e5 + 2;
void solve_case() {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int &x : c) cin >> x;
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    vector<int> dp(n);
    for(int i = 1; i < n; i++) {
        dp[i] = c[i] + 1 + abs(a[i] - b[i]);
        if(a[i] != b[i])
            dp[i] = max(dp[i], c[i] + 1 + dp[i - 1] - abs(a[i] - b[i]));
    }
    cout << *max_element(all(dp)) << '\n';
}
