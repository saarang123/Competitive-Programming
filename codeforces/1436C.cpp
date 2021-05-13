#include <bits/stdc++.h>
using namespace std;
#define int long long

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

void init(int n) {
    f[0] = inv[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = i * f[i - 1]; f[i] %= mod;
        inv[i] = fexpo(f[i], mod - 2);
    }
}

int nPr(int n, int r) { return (f[n] * inv[n - r]) % mod; }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, x, pos;
    cin >> n >> x >> pos;
    init(n);
    int mn = 0, mx = n, low = 0, above = 0;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        if(mid == pos) mn = mid + 1;
        else if(mid < pos)
            mn = mid + 1, low++;
        else
            above++, mx = mid;
    }
    //cout << low << " " << above << endl;
    int ans = f[n - above - low - 1];
    ans *= nPr(n - x, above); ans %= mod;
    ans *= nPr(x - 1, low); ans %= mod;
    cout << ans << endl;
    return 0;
}
