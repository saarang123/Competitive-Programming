#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, m, tx = 0;
    cin >> n >> m;
    vector<int> t(m), a(m), b(m), g[n], c(n), tout(n);
    for(int i = 0; i < m; i++) {
        cin >> t[i] >> a[i] >> b[i];
        --a[i], --b[i];
        if(t[i]) 
            g[a[i]].push_back(b[i]);
    }
    function<bool(int v)> dfs = [&] (int v) {
        c[v] = 1;
        for(int u : g[v]) {
            if(c[u] == 1)
                return true;
            else if(!c[u])
                if(dfs(u))
                    return true;
        }
        c[v] = 2;
        tout[v] = tx++;
        return false;
    };
    for(int i = 0; i < n; i++)
        if(!c[i] && dfs(i))
            return cout << "NO" << '\n', 0;
    cout << "YES" << '\n';
    for(int i = 0; i < m; i++) {
        if(!t[i])
            if(tout[a[i]] < tout[b[i]])
                swap(a[i], b[i]);
        cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
    }
    return 0;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}