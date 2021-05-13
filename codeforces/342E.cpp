#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3, lgn = 19;
vector<array<int, 2>> g[mxn];
int sz[mxn], par[mxn], dt[mxn], lvl[mxn], d[mxn], ans[mxn], dist[lgn][mxn];
bool cent[mxn];
int n, m, cnt;

int dfssz(int v, int p = -1) {
    sz[v] = 1;
    for(auto &[u, w] : g[v]) if(u != p && !cent[u])
        sz[v] += dfssz(u, v);
    return sz[v];
}

int fcent(int v, int p = -1) {
    for(auto &[u, w] : g[v]) if(u != p && !cent[u])
        if(sz[u] > cnt / 2)
            return fcent(u, v);
    return v;
}

void fdist(int v, int p, int l) {
    for(auto &[u, w] : g[v]) if(u != p && !cent[u]) {
        dist[l][u] = dist[l][v] + w;
        fdist(u, v, l);
    }
}

void decompose(int v, int p = -1, int dep = 0) {
    cnt = dfssz(v);
    int centroid = fcent(v);
    par[centroid] = p;
    lvl[centroid] = dep;
    dist[dep][centroid] = 0;
    fdist(centroid, -1, dep);
    cent[centroid] = true;
    for(auto &[u, w] : g[centroid]) if(u != p && !cent[u])
        decompose(u, centroid, dep + 1);
}

void upd(int v) {
    for(int p = v; p != -1; p = par[p])
        ans[p] = min(ans[p], dist[lvl[p]][v]);
}

int qry(int v) {
    int res = ans[0];
    for(int p = v; p != -1; p = par[p])
        res = min(res, ans[p] + dist[lvl[p]][v]);
    return res;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    decompose(1, -1, 0);
    memset(ans, 0x7f, sizeof ans);
    upd(1);
    while(m--) {
        int t, v;
        cin >> t >> v;
        if(t == 1)
            upd(v);
        else
            cout << qry(v) << '\n';
    }
    return 0;
}