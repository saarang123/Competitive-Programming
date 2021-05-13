#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
const string out[] = {"none", "any", "at least one"};
vector<array<int, 3>> ed[N];
vector<array<int, 2>> g[N];
int ans[N], par[N], sz[N], tin[N], low[N], txr;

int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }

void join(int a, int b) {
    a = fin(a); b = fin(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

void dfs(int v, int p = -1) {
    tin[v] = low[v] = ++txr;
    for(auto tx : g[v]) {
        int u = tx[0], id = tx[1];
        if(id == p) continue;  //multiedges possible
        if(tin[u] == -1) {
            dfs(u, id);
            low[v] = min(low[v], low[u]);
            if(low[u] > tin[v]) ans[id] = 1; //bridge
        } else {
            low[v] = min(low[v], tin[u]);
        }
    }
}

void solve(int w) {
    for(auto tx : ed[w]) {
        int v = fin(tx[0]), u = fin(tx[1]), id = tx[2];
        g[u].clear(); g[v].clear();
        tin[u] = tin[v] = -1;
        low[u] = low[v] = -1;
    }
    txr = 0;
    for(auto tx : ed[w]) {
        int v = fin(tx[0]), u = fin(tx[1]), id = tx[2];
        if(u == v) ans[id] = 0; //already connected
        else {
            ans[id] = 2; //atleast one
            g[v].push_back({u, id});
            g[u].push_back({v, id});
        }
    }
    for(auto tx : ed[w]) {
        int v = fin(tx[0]), u = fin(tx[1]), id = tx[2];
        if(tin[v] == -1) dfs(v);
        else if(tin[u] == -1) dfs(u);
    }
    for(auto tx : ed[w]) join(tx[0], tx[1]);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) sz[i] = 1, par[i] = i;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ed[w].push_back({u, v, i});
    }
    for(int i = 1; i < N; i++)
        solve(i);
    for(int i = 0; i < m; i++) cout << out[ans[i]] << '\n';
    return 0;
}
