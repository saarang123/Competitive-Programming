#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


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
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n + 3), d(n + 3), f(n + 3);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[1]; a[n + 1] = a[n];
    for(int i = 2; i <= n; i++)
        f[i] = f[i - 1] + (a[i] - a[i - 1] - 1);
    for(int i = n - 1; i >= 0; i--)
        d[i] = (a[i + 1] - a[i] - 1);
    for(int i = 1; i <= n; i++)
        d[i] += d[i - 1];
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = d[r - 1] - d[l - 1] + f[r] - f[l] + (k - a[r]) + (a[l] - 1);
        cout << ans << '\n';
    }
}
