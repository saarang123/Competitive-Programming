#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef saarang
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Taken from neal(https://codeforces.com/profile/neal)
template<const int MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    static int inv_mod(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }

    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

    _m_int inv() const {
        return inv_mod(val);
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator << (ostream &os, const _m_int &m) { return os << m.val; }
    friend istream& operator >> (istream& is, _m_int &m) {is >> m.val; m.val %= MOD; return is;}
};

const int MOD = 1e9 + 7;
using mint = _m_int<MOD>;
const int MXK = 15;
vector<mint> fact(MXK), inv(MXK);
void init() {
    fact[0] = inv[0] = mint(1);
    for(int i = 1; i < MXK; i++) {
        (fact[i] = fact[i - 1] * i);
    }
    for(int i = 1; i < MXK; i++)
        inv[i] = fact[i].inv();
}

mint nCr(int n, int r) {
    return (r > n ? mint(0) : ((fact[n] * inv[r]) * inv[n - r]));
}

const int MXN = 500 * 1000 + 3;
vector<int> g[MXN];
mint C[MXK][MXK], dp[MXN][MXK];
int n, k;
mint ans;

void dfs(int v, int p = -1) {
    if(g[v].size() == 1) 
        return dp[v][0] = 1, void();
    vector<mint> tmp(k + 1);
    for(int u : g[v]) if(u != p) {
        dfs(u, v);
        for(int i = 0; i <= k; i++) {
            tmp[i] = 0;
            for(int j = 0; j <= i; j++)
                tmp[i] += C[i][j] * dp[u][j]; //(d + 1) ^ i
        }
        for(int i = 0; i <= k; i++)
            ans += C[k][i] * dp[v][i] * tmp[k - i]; //(a+b)^k= \sum a^i * b^(k-i)
        for(int i = 0; i <= k; i++)
            dp[v][i] += tmp[i];
    }
}

bool line() {
    bool ok = true;
    for(int i = 1; i <= n && ok; i++)
        ok = ok && g[i].size() <= 2;
    return ok;
}

void solve() {
    cin >> n >> k;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        memset(dp[i], 0, sizeof dp[i]);
    }
    for(int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if((line() && k == 1) || n == 2)
        return cout << n - 1 << ' ' << mint(2).pow(n - 2) << '\n', void();
    int root = -1;
    for(int i = 1; i <= n && root < 0; i++)
        if(g[i].size() > 1)
            root = i;
    dfs(root);
    cout << ans << ' ' << 1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    init();
    for(int i = 0; i < MXK; i++)
        for(int j = 0; j <= i; j++)
            C[i][j] = nCr(i, j);

    int tc; cin >> tc;
    while(tc--)
        solve();
    return 0;
}