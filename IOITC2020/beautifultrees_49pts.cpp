#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int MXN = 500 * 1000 + 3, LGN = 20;
const int mod = 1e9 + 7;

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

ll c[15][15], fact[15], inv[15];

ll nCr(int n, int r) {
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

struct LCA {
    int n,i,j,t;
    vector<vector<int>> graph, par;
    vector<int> dt;
    void init(int x) {
        n = x; t = ceil(log2(n));
        dt.resize(n + 2);
        graph = vector<vector<int>>(n + 2, vector<int>());
        par = vector<vector<int>>(n + 2, vector<int>(t + 2));
    }
    void add(int v, int u) { graph[v].push_back(u); graph[u].push_back(v); }
    void build(int v = 1, int p = 1, int d = 0) {
        dt[v] = d; par[v][0] = p;
        for(i = 1; i < t; i++) 
            par[v][i] = par[par[v][i - 1]][i - 1];
        for(int u: graph[v]) {
            if(u != p) build(u, v, d + 1);
        }
    }
    int kth(int a, int diff) {
        for(i = 0; i < t; i++) {
            if(diff & (1 << i))
                a = par[a][i];
        }
        return a;
    }
    int lca(int a, int b) {
        if(dt[a] < dt[b]) swap(a, b);
        a = kth(a, dt[a] - dt[b]);
        if(a == b) return a;
        for(i = t - 1; i >= 0; i--) {
            if(par[a][i] != par[b][i]) { a = par[a][i]; b = par[b][i]; }
        }
        return par[a][0];
    }
    bool line() {
        bool ok = true;
        for(i = 1; i <= n && ok; i++)
            ok = ok && graph[i].size() <= 2;
        return ok;
    }
    int dist(int a, int b) { return dt[a] + dt[b] - 2 * dt[lca(a,b)]; }
};

void solve() {
    int n, k;
    cin >> n >> k;
    LCA g; g.init(n);
    for(int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g.add(u, v);
    }
    if(g.line() && k == 1)
        return cout << n - 1 << ' ' << fexpo(2LL, n - 2) << '\n', void();
    g.build();
    int ans = 0;
    for(int i = 1; i <= n; i++) if(g.graph[i].size() == 1)
        for(int j = 1; j < i; j++) if(g.graph[j].size() == 1)
            (ans += fexpo(g.dist(i, j), k)) %= mod;
    cout << ans << ' ' << 1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 14; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = fexpo(fact[i], mod - 2);
    }
    for(int i = 0; i < 12; i++)
        for(int j = 0; j <= i; j++)
            c[i][j] = nCr(i, j);
    int tc; cin >> tc;
    while(tc--)
        solve();
    return 0;
}