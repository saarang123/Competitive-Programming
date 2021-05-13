#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 2;
const int inf = 1e9;
vector<int> g[N];
int sz[N], ans[N];

int dfs(int v, int p) {
    sz[v] = 1;
    int c = 1, t = 0;
    for(int u : g[v]) if(u != p) {
        sz[v] += dfs(u, v);
        ans[v] += ans[u];
        t++;
    }
    while(c <= t) c *= 2, ans[v]++;
    ans[v] += t;
    return sz[v];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans[1] << '\n';
    return 0;
}
