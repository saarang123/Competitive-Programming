#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 2e5 + 2;
int f[N], inv[N];

template<class T>
T fexpo(T a, long long b) {
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

void init() {
    f[0] = 1;
    for(int i = 1; i < N; i++) (f[i] = i * f[i - 1]) %= mod;
    inv[0] = 1;
    for(int i = 1; i < N; i++) inv[i] = fexpo(f[i], mod - 2);
}

int nCr(int n, int r) {
    if(r > n) return 0;
    return ((f[n] * inv[n - r]) % mod * inv[r]) % mod;
}

void solve_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(all(a));
    int ans = 0;
    for(int i = m - 1; i < n; i++) {
        int x = lower_bound(all(a), a[i] - k) - a.begin();
        (ans += nCr(i - x, m - 1)) %= mod;
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    //freopen("input.txt", "r", stdin);
    init();
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
