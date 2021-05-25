#include <bits/stdc++.h>
using namespace std;
const int MXN = 605;

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }

int n, m;
vector<array<int, 2>> adj[MXN];
int dt[MXN][MXN], cost[MXN][MXN];
bool vis[MXN];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i = 0; i < n; i++) 
    	sort(adj[i].begin(), adj[i].end());
    for(int i = 0; i < n; i++) {
        memset(cost[i], 0x7f, sizeof cost[i]);
        for(auto [v, w] : adj[i]) {
            for(int k = v; k < n; k++) remin(cost[i][k], k - v + w);
            for(int k = 0; k < v; k++) remin(cost[i][k], n + k - v + w);
        }
    }
    memset(dt, 0x7f, sizeof dt);
    for(int x = 0; x < n; x++) {
        dt[x][x] = 0;
        priority_queue<array<int, 2>> pq;
        pq.push({0, x});
        while (!pq.empty()) {
            int a = pq.top()[1];
            pq.pop();
            if (vis[a]) continue;
            vis[a] = 1;
            for(int i = 0; i < n; i++) {
                if (remin(dt[x][i], dt[x][a] + cost[a][((i - dt[x][a]) % n + n) % n])) {
                    pq.push({-dt[x][i], i});
                }
            }
        }
        memset(vis, 0, sizeof vis);
    }
    for(int i = 0; i < n; i++) 
    	for(int j = 0; j < n; j++)
    		cout << dt[i][j] << " \n"[j == n-1];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    //std::cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}