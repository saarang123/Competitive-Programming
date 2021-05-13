#include <bits/stdc++.h>
#include <traffic.h>
using namespace std;
using ll = long long;

int LocateCentre(int N, int *P, int *S, int *D) {
    int n = N;
    vector<ll> g[n], sz(n), dp(n);
    for(int i = 0; i < n - 1; i++)
            g[S[i]].push_back(D[i]), g[D[i]].push_back(S[i]);
    function<int(int v, int p)> dfs = [&] (int v, int p) {
        sz[v] = P[v];
        for(int u : g[v]) if(u != p) {
            sz[v] += dfs(u, v);
        }
        return sz[v];
    };
    function<void(int v, int p)> reroot = [&] (int v, int p) {
        for(int u : g[v]) dp[v] = max(dp[v], sz[u]);
        for(int u : g[v]) if(u != p) {
            sz[v] -= sz[u];
            sz[u] += sz[v];
            reroot(u, v);
            sz[u] -= sz[v];
            sz[v] += sz[u];
        }
    };
    dfs(0, -1); reroot(0, -1);
    ll ans = dp[0], id = 0;
    for(int i = 0; i < n; i++) if(dp[i] < ans) ans = dp[i], id = i;
    return id;
}
/*
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    int p[n], s[n], d[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 1; i < n; i++) {
        cin >> s[i - 1] >> d[i - 1];
    }
    cout << LocateCentre(n, p, s, d) << '\n';
    return 0;
}*/
