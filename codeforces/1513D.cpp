#include <bits/stdc++.h>
using namespace std;
using ld = long double;
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
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

template<class T> struct SparseTable { // comb(ID,b) = b
    T ID = T();
    function<T(const T&,const T&)> comb;
    int n, k; vector<vector<T>> seg;
    void init(int _n, T base, function<T(const T&,const T&)> join) {
        n = _n; k = lg(n); comb = join; ID = base; seg.assign(_n + 1, vector<T> (k + 1, ID)); }
    int lg(int x) { return 31 - __builtin_clz(x); }   //CHECK THIS
    void build(vector<T> a) {
        for(int i = 1; i <= n; i++) seg[i][0] = a[i];
        for(int j = 1; j <= k; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                seg[i][j] = comb(seg[i][j - 1], seg[i + (1 << (j - 1))][j - 1]);
    }
    T query(int L, int R) {
        int j = lg(R - L + 1);
        return comb(seg[L][j], seg[R - (1 << j) + 1][j]);
    }
};

struct UFDS {
    int n, c;
    vector<int> len, par;
    void init(int x, int y = 1) {
        n = x;
        c = y;
        par.resize(n+2);
        len.assign(n+2, 1);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }
    bool join(int a, int b) {
        a = fin(a); b = fin(b);
        if(a == b) return false;
        if(rng() % 2) swap(a, b);
        if(c && len[a] < len[b])
            swap(a, b);
        par[b] = a;
        if(c) len[a] += len[b];
        return true;
    }
    int sz(int x) { return len[fin(x)]; }
};

void solve_case() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    SparseTable<int> st; st.init(n, 0, [&] (int x, int y) {
        return __gcd(x, y);
    });
    st.build(a);
    UFDS uf; uf.init(n);
    vector<array<int, 3>> ed;
    for(int i = 1; i < n; i++)
        ed.push_back({p, i, i + 1});
    for(int i = 1; i <= n; i++) {
        int mn = i, mx = n;
        while(mn < mx) {
            int mid = (mn + mx + 1) >> 1;
            if(st.query(i, mid) == a[i])
                mn = mid;
            else
                mx = mid - 1;
        }
        int k = mn;
        mn = 1, mx = i;
        while(mn < mx) {
            int mid = (mn + mx) >> 1;
            if(st.query(mid, i) == a[i])
                mx = mid;
            else
                mn = mid + 1;
        }
        ed.push_back({a[i], mn, k});
    }
    sort(ed.begin(), ed.end());
    long long ans = 0;
    for(auto &[w, i, j] : ed) {
        if(uf.fin(i) == uf.fin(j))
            continue;
        for(int k = i; k < j; k++) 
            if(uf.join(k, k + 1))
                ans += w;
    }
    cout << ans << '\n';
}