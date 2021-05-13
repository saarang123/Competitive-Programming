#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
int par[mxn], sz[mxn], a[mxn], b[mxn];

int find(int v) { return par[v] == v ? v : par[v] = find(par[v]); }

bool join(int u, int v) {
    u = find(u); v = find(v);
    if(u == v)
        return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int j = 1; j <= n; j++) 
        cin >> b[j];

    vector<array<int, 3>> ed;
    long long ans = 0;
    for(int i = 1; i <= m; i++) {
        int c; cin >> c;
        for(int _ = 0; _ < c; _++) {
            int x; cin >> x;
            ed.push_back({a[i] + b[x], i, m + x});
        }
    }
    iota(par, par + n + m + 1, 0);
    memset(sz, 1, sizeof sz);
    sort(ed.begin(), ed.end(), greater<>());
    for(auto &[w, i, j] : ed) {
        if(!(join(i, j)))
            ans += w;
    }
    cout << ans << '\n';
    return 0;
}