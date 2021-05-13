#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dijkstra(const vector<vector<pair<int, int>>> g) {
    int n = g.size();
    vector<int> dt(n, 1e16);
    dt[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        int on = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(d != dt[on]) continue;
        if(d & 1) {
            d--;
        }
        for(auto e : g[on]) {
            int nxt = d + e.second;
            int to = e.first;
            if(dt[to] > nxt) {
                dt[to] = nxt;
                pq.push({nxt, to});
            }
        }
    }
    return dt;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n);
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, 2 * c);
        g[v].emplace_back(u, 2 * c);
    }
    for(int i = 0; i < q; i++) {
        int x, d;
        cin >> x >> d;
        g[0].emplace_back(x, 2 * d + 1);
    }
    auto dt = dijkstra(g);
    int ans = q;
    for(auto d : dt) {
        ans -= d & 1;
    }
    cout << ans << '\n';
}