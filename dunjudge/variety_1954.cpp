#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 2;
const int inf = 1e16;
vector<array<int, 2>> g[N];
int dt[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, m, w;
    cin >> n >> m >> w;
    for(int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k; a++; b++;
        g[a - 1].push_back({b, k});
    }
    for(int i = 1; i <= n; i++)
        g[i].push_back({i - 1, w});
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    for(int i = 0; i <= n; i++) dt[i] = inf;
    pq.push({0, 0});
    dt[0] = 0;
    while(!pq.empty()) {
        int v = pq.top()[1], w = pq.top()[0];
        pq.pop();
        for(auto to : g[v]) {
            int u = to[0], wt = to[1];
            if(dt[v] + wt < dt[u]) {
                dt[u] = dt[v] + wt;
                pq.push({dt[u], u});
            }
        }
    }
    //for(int i = 0; i <= n; i++) cout << dt[i] << ' '; cout << '\n';
    cout << (dt[n] >= inf ? -1 : dt[n]) << '\n';
    return 0;
}