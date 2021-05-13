#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =   500 * 1000 + 3;
const int mod = 1e9 + 7;
ll bit[N];
int n;

template<class T>
struct CoordinateCompression {
    std::vector<T> cmp;
    CoordinateCompression(std::vector<T> &a) {
        cmp = a;
        std::sort(cmp.begin(), cmp.end());
        cmp.resize(std::unique(cmp.begin(), cmp.end()) - cmp.begin());  //compressing element
    }
    int getL(T x) {  //index of closest element <= x
        int id = std::lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
        if(id >= cmp.size() || cmp[id] > x) id--;
        return id;
    }
    int getR(T x) {   //index of closest element >= x
        int id = std::lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
        return id;
    }
};

void upd(int x, ll val) {
    if(x <= 0) return;
    for(; x <= n; x += (x & -x))
        bit[x] += val, bit[x] %= mod;
}

ll qry(int x) {
    ll res = 0;
    for(; x > 0; x -= (x & -x)) res += bit[x], res %= mod;
    return res;
}

ll qry(int l, int r) {
    l = max(l, 1); r = min(r, n);
    return (qry(r) - qry(l - 1) + mod) % mod;
}

int ballgame(int N, int L, int D, int H[], int C[]) {
    n = N;
    vector<ll> c(n), h(n);
    for(int i = 0; i < n; i++) c[i] = C[i], h[i] = H[i];
    vector<array<ll, 2>> a(n);
    for(int i = 0; i < n; i++) a[i] = {h[i], c[i]};
    CoordinateCompression<ll> cc(c);
    sort(a.begin(), a.end());
    vector<ll> dp(n + 1);
    dp[1] = 1;
    upd(cc.getL(a[0][1]) + 1, 1);
    for(int i = 2; i <= n; i++) {
        int l = cc.getR(a[i - 1][1] - D) + 1, r = cc.getL(a[i - 1][1] + D) + 1;
        dp[i] += qry(l, r);
        dp[i] %= mod;
        upd(cc.getL(a[i - 1][1]) + 1, dp[i]);
    }
    return dp[n];
}

/*
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int l, d;
    cin >> n >> l >> d;
    int h[n], c[n];
    for(int i = 0; i < n; i++) cin >> h[i] >> c[i];
    cout << ballgame(n, l, d, h, c) << '\n';
    return 0;
}*/
