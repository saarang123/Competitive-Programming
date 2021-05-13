#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 3;
vector<array<int, 2>> g[N];
vector<int> dt;

void dfs(int v, int p, int d) {
    dt[v] = d;
    for(auto x : g[v]) {
        int u = x[0], w = x[1];
        if(u == p) continue;
        dfs(u, v, d + w);
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    dt.resize(n);
    for(int i = 1; i < n; i++) {
        int v, u, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(a, -1, 0);
    auto da = dt;
    dfs(b, -1, 0);
    auto db = dt;
    // for(int x : da) cout << x << ' '; cout << '\n';
    // for(int x : db) cout << x << ' '; cout << '\n';
    set<array<int, 2>> mx;
    for(int i = 0; i < n; i++) {
        mx.insert({da[i] + db[i], i});
    }
    int x = 0, y = 0, used = 0;
    bool turn = 0;
    while(used < n) {
        auto id = *mx.rbegin();
        mx.erase(id);
        if(turn) y += db[id[1]];
        else x += da[id[1]];
        used++; turn ^= 1;
    }
    cout << x - y << '\n';
    return 0;
}