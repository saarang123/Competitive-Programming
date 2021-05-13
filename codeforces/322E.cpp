#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<int> g[N];
int sz[N], ans[N], x;
bool c[N];

int dfssz(int v, int p) {
    sz[v] = 1;
    for(int u : g[v]) if(u != p && !c[u])
        sz[v] += dfssz(u, v);
    return sz[v];
}

int fcent(int v, int p) {
    for(int u : g[v]) 
        if(u != p && !c[u] && sz[u] > (sz[x] >> 1))
            return fcent(u, v);
    return v;
}

void fix(int v, int p, int lvl) {
    assert(lvl < 26);
    dfssz(v, p);
    x = v;
    int centroid = fcent(v, p);
    ans[centroid] = lvl;
    c[centroid] = true;
    for(int u : g[centroid]) if(u != p && !c[u])
        fix(u, centroid, lvl + 1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int u, v, _ = 0; _ < n - 1; _++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fix(1, -1, 0);
    for(int i = 1; i <= n; i++)
        cout << char('A' + ans[i]) << ' ';
    cout << '\n';
    return 0;
}