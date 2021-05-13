#include <bits/stdc++.h>
using namespace std;

const int N = 4 * 100 * 1000 + 3;
vector<array<int, 2>> g[N];
vector<bool> bridge, visited, oriented;
vector<int> tin, low, sz, par;
int tx = 0;
vector<array<int, 2>> edges;

void init(int n, int m) {
    edges.resize(m);
    oriented.resize(m);
    bridge.resize(m);
    tin.assign(n + 2, -1);
    low.assign(n + 2, 0);
    visited.resize(n + 2);
    sz.assign(n + 2, 1);
    par.resize(n + 2);
    iota(par.begin(), par.end(), 0);
}

int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }

void join(int a, int b) {
    a = fin(a); b = fin(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

void dfs(int v, int p) {
    low[v] = tin[v] = ++tx;
    for(array<int, 2> &x : g[v]) {
        int u = x[0], id = x[1];
        if(u == p) continue;
        if(tin[u] == -1) {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] > tin[v]) bridge[id] = true; //bridge
        } else
            low[v] = min(low[v], tin[u]);
    }
}

void orient(int v, int p) {
    visited[v] = true;
    for(auto &x : g[v]) {
        int u = x[0], id = x[1];
        if(u == p) continue;
        if(bridge[id]) edges[id] = {u, v};
        else if(!oriented[id]) edges[id] = {v, u};
        oriented[id] = true;
        if(!visited[u])
            orient(u, v);
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    init(n, m);
    for(int u, v, _ = 0; _ < m; _++) {
        cin >> u >> v;
        g[u].push_back({v, _});
        g[v].push_back({u, _});
        edges[_] = {u, v};
    }
    dfs(1, -1);
    //for(int i = 0; i < m; i++) cout << bridge[i]; cout << '\n';
    for(int i = 0; i < m; i++) if(!bridge[i]) {
        join(edges[i][0], edges[i][1]); //dsu for component sizes other than bridges
    }
    int id = 1;
    for(int i = 1; i <= n; i++)
        if(sz[fin(i)] > sz[fin(id)]) //largest components
            id = i;
    cout << sz[fin(id)] << '\n';
    orient(id, -1); //directing towards largest components
    for(int i = 0; i < m; i++) cout << edges[i][0] << ' ' << edges[i][1] << '\n';
    return 0;
}
