#include <bits/stdc++.h>
using namespace std;

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
const int N = 5003;
template<class T>
T fexpo(T a, long long b) {
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

mint fact[N], inv[N], two[N];

void init() {
	fact[0] = inv[0] = two[0] = mint(1);
	for(int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i;
		two[i] = two[i - 1] * 2;
	}
	for(int i = 1; i < N; i++)
		inv[i] = fexpo(fact[i], MOD - 2);
}

mint nCr(int n, int r) {
	return (r > n ? mint(0) : ((fact[n] * inv[r]) * inv[n - r]));
}

const int MXN = 5003;
mint dp[MXN][MXN], c[MXN];
int deg[MXN], par[MXN], sz[MXN];
int n, m, cc;

void reset() {
	cc = n;
	for(int i = 0; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
		deg[i] = 0;
	}
}

int find(int v) {
	return par[v] == v ? v : par[v] = find(par[v]);
}

bool join(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v)
		return false;
	cc--;
	if(sz[u] < sz[v])
		swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
	return true;
}

void solve() {
	cin >> n >> m;
	reset();
	int mx = 0;
	for(int u, v, i = 0; i < m; i++) {
		cin >> u >> v;
		join(u, v);
		deg[u]++;
		deg[v]++;
		mx = max({mx, deg[u], deg[v]});
	}
	if(mx > 2)
		return cout << 0 << '\n', void();
	if(n <= 2)
		return cout << 0 << '\n', void();
	memset(dp, 0, sizeof dp);
	memset(c, 0, sizeof c);
	int cnt[] = {0, 0};
	vector<bool> seen(n + 1);
	for(int i = 1; i <= n; i++) {
		int v = find(i);
		if(!seen[v]) {
			seen[v] = true;
			cnt[sz[v] > 1]++;
		}
	}
	//cout << cnt[0] << ' ' << cnt[1] << '\n';
	if(cnt[0] + cnt[1] == 1) {
		if(sz[find(1)] > 2)
			cout << 1 * fact[n].pow(2 * n) << '\n';
		else
			cout << 0 << '\n';
		return;
	}
	c[0] = c[1] = c[2] = c[3] = 1;
	for(int i = 4; i <= n; i++)
		c[i] = c[i - 1] * i;
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[1][1] = 0;
	dp[2][0] = 0;
	dp[2][1] = 1;
	dp[2][2] = 2;
	for(int i = 3; i <= cc; i++) {
		for(int j = i; j >= 3; j--) {
			mint add = nCr(i, j) * (fact[j] / (mint(2) * mint(j))) * dp[i - j][0];
			if(j == i - j)
				add /= 2;
			dp[i][0] += add;
		}
		for(int j = 1; j <= i; j++)
			dp[i][j] = dp[i][j - 1] * 2;
	}
	// for(int i = 0; i <= n; i++) {
	// 	for(int j = 0; j <= n; j++)
	// 		cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
    mint ans = dp[cc][cnt[1]] * fact[n].pow(2 * n);
	cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    init();
    int tc; cin >> tc;
    while(tc--)
    	solve();
    return 0;
}