#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define int long long
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}
const int mod = 1e9 + 7;
template <int MOD = mod>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + MOD : v % MOD) {}
	int val;

	void operator += (modBase<MOD> o) { *this = *this + o; }
	void operator -= (modBase<MOD> o) { *this = *this - o; }
	void operator *= (modBase<MOD> o) { *this = *this * o; }
	modBase<MOD> operator * (modBase<MOD> o) { return (int)((long long) val * o.val % MOD); }
	modBase<MOD> operator / (modBase<MOD> o) { return *this * fexp(o, MOD - 2); }
	modBase<MOD> operator + (modBase<MOD> o) { return (val + o.val) % MOD; }
	modBase<MOD> operator - (modBase<MOD> o) { return (val - o.val + MOD) % MOD; }

	friend std::ostream& operator << (std::ostream &os, const modBase<MOD> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<MOD> &p) {
        is >> p.val; p.val %= MOD;
        return is;
	}
};
using mint = modBase<mod>;

const int N = 1e5 + 2;
mint ans = 0;
int par[N], sz[N];
mint mx[N], ht[N], w[N];
bool u[N];
vector<array<int, 3>> a;

mint cnt(mint a, mint b) {
    return (a * (a + 1) * b * (b + 1)) / mint(4);
}

void init(int n) { for(int i = 0; i <= n; i++) mx[i] = w[i], par[i] = i, sz[i] = 1; }

int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }

void join(int a, int b, mint h) {
    if(!u[a] || !u[b]) return;
    a = fin(a); b = fin(b);
    if(sz[a] < sz[b]) swap(a, b);
    ans -= cnt(mx[a], h);
    ans -= cnt(mx[b], h);
    par[b] = a;
    mx[a] += w[b];
    ans += cnt(mx[a], h);
}

void activate(int v, mint h) {
    u[v] = true;
    ans += cnt(mx[v], h);
    join(v, v + 1, h); join(v - 1, v, h);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> ht[i + 1];
        a[i][0] = ht[i + 1].val;
    }
    for(int i = 0; i < n; i++) {
        cin >> w[i + 1];
        a[i][1] = w[i + 1].val;
        a[i][2] = i + 1;
    }
    init(n);
    sort(all(a)); reverse(all(a));
    int j = 0;
    for(int i = 0; i < n; i = j) {
        while(j < n && a[j][0] >= a[i][0]) {
            activate(a[j][2], a[i][0]);
            j++;
        }
    }
    cout << ans << '\n';
    return 0;
}
