#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MXN = 603;
int dt[MXN][MXN], n, m;
vector<array<int, 2>> g[MXN];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> m;
    for(int a, b, c, i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for(int i = 0; i < n; i++)
        g[i].push_back({i, 1});
    for(int i = 0; i < n; i++) {
        memset(dt, 0x2f, sizeof dt);
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        dt[i][0] = 0;
        pq.push({0, 0, i});
        while(!pq.empty()) {
            auto [d, t, v] = pq.top();
            pq.pop();
            if(dt[v][t] != d)
                continue;
            for(auto &[x, w] : g[v]) {
                int u = (x + t) % n;
                if(t + w < MXN && dt[u][t + w] > d + w) {
                    dt[u][t + w] = d + w;
                    pq.push({d + w, t + w, u});
                }
            }
        }
        for(int j = 0; j < n; j++)
            cout << *min_element(dt[j], dt[j] + MXN) << ' ';
        cout << '\n';
    }
    return 0;
}