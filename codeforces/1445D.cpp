#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
const int N = 150 * 1000 + 3;
vector<int> f(2 * N);

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

void init(int n) {
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = i * f[i - 1], f[i] %= mod;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    init(2 * n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end()); sort(b.begin(), b.end(), greater<int>());
    int sum = 0;
    for(int i = 0; i < n; i++) sum += abs(a[i] - b[i]);
    sum %= mod;
    int inv = fexpo(f[n], mod - 2);
    int ans = (((f[2 * n] * inv) % mod * inv) % mod * sum) % mod;
    cout << ans << '\n';
    return 0;
}
