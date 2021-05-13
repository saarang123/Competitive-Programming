#include <bits/stdc++.h>
using namespace std;

struct LCA {
    int n,i,j,t;
    vector<vector<int>> g, par;
    vector<int> dt;
    void init(int x) {
        n = x; t = ceil(log2(n));
        dt.resize(n + 2);
        g = vector<vector<int>>(n + 2, vector<int>());
        par = vector<vector<int>>(n + 2, vector<int>(t + 2));
    }
    void add(int v, int u) { g[v].push_back(u); g[u].push_back(v); }
    void build(int v = 1, int p = 1, int d = 0) {
        dt[v] = d; par[v][0] = p;
        for(i=1; i<t; i++) {
            if(par[par[v][i-1]][i-1] != -1) par[v][i] = par[par[v][i-1]][i-1];
        }
        for(int u: g[v]) {
            if(u != p) build(u, v, d+1);
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
    int dist(int a, int b) { return dt[a] + dt[b] - 2 * dt[lca(a,b)]; }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    LCA tree;
    tree.init(n);
    for(int u, v, _ = 1; _ < n; _++) {
        cin >> u >> v;
        tree.add(u, v);
    }
    tree.build();
    vector<int> a(m + 1);
    vector<set<int>> one(n + 1), two(n + 1);
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        one[a[i]].insert(i);
    }
    for(int i = 2; i <= m; i++) {
        two[tree.lca(a[i], a[i - 1])].insert(i - 1);
    }
    while(q--) {
        int tp; cin >> tp;
        if(tp == 1) {
            int x, v; cin >> x >> v;
            one[a[x]].erase(x);
            if(x < m) two[tree.lca(a[x], a[x + 1])].erase(x);
            if(x > 1) two[tree.lca(a[x], a[x - 1])].erase(x - 1);
            a[x] = v;
            one[a[x]].insert(x);
            if(x < m) two[tree.lca(a[x], a[x + 1])].insert(x);
            if(x > 1) two[tree.lca(a[x], a[x - 1])].insert(x - 1);
        }
        else {
            int l, r, v;
            cin >> l >> r >> v;
            int id = 0;
            if(!one[v].empty()) {
                auto x = one[v].lower_bound(l);
                if(x != one[v].end()) id = *x;
                if(l <= id && id <= r) {
                    cout << id << ' ' << id << endl;
                    continue;
                }
            }
            if(!two[v].empty()) {
                auto x = two[v].lower_bound(l);
                if(x != two[v].end()) id = *x;
                if(l <= id && id + 1 <= r) {
                    cout << id << ' ' << id + 1 << endl;
                    continue;
                }
            }
            cout << -1 << ' ' << -1 << endl;
        }
    }
    return 0;
}
