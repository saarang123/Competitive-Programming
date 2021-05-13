#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define int long long

const int N = 1003;
vector<array<int, 2>> g[N];
vector<vector<int>> d(N, vector<int>(N));
int n;

vector<int> dijkstra(int v) {
    vector<int> dt(n + 2, -1);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, v});
    dt[v] = 0;
    while(!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();
        for(auto x : g[u]) {
            int to = x[0], w = x[1];
            if(dt[to] == -1 || dt[to] > dt[u] + w) {
                dt[to] = dt[u] + w;
                pq.push({dt[to], to});
            }
        }
    }
    return dt;
}

void solve_case() {
    int i,j,m,k;
    cin >> n >> m >> k;
    vector<array<int, 2>> path(k), edge(m);
    for(i = 0; i < m; i++) {
        int v, u, w; cin >> v >> u >> w;
        g[v].pb({u, w}); g[u].pb({v, w});
        edge[i] = {v, u};
    }
    for(i = 0; i < k; i++) {
        cin >> path[i][0] >> path[i][1];
    }
    for(i = 1; i <= n; i++) d[i] = dijkstra(i);
    int ans = 0;
    for(array<int, 2> a : path) ans += d[a[0]][a[1]];
    for(i = 0; i < m; i++) {
        int cur = 0, x = edge[i][0], y = edge[i][1];
        for(j = 0; j < k; j++) {
            int u = path[j][0], v = path[j][1];
            cur += min(d[u][v], min(d[u][x] + d[y][v], d[u][y] + d[x][v]));
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
