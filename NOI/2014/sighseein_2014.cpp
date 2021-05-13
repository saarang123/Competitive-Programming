#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, e, q;
    cin >> n >> e >> q;
    vector<array<int, 2>> g[n + 1];
    vector<array<int, 3>> edge(e);
    for(int i = 0; i < e; i++) cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    sort(edge.begin(), edge.end(), greater<array<int, 3>>());
    UFDS dsu; dsu.init(n);
    for(auto ed : edge) {
        int v = ed[1], u = ed[2], w = ed[0];
        if(dsu.join(u, v)) {
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }
    }
    vector<int> ans(n + 1, inf);
    function<void(int v, int p, int mx)> dfs = [&] (int v, int p, int mx) {
        ans[v] = min(ans[v], mx);
        for(auto tx : g[v]) if(tx[0] != p) {
            dfs(tx[0], v, min(tx[1], mx));
        }
    };
    dfs(1, -1, inf);
    while(q--) {
        int v; cin >> v;
        cout << ans[v] << '\n';
    }
    return 0;
}
