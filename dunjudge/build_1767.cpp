#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct UFDS {
    int n, c;
    vector<int> len, par;
    void init(int x, int y = 1) {
        n = x;
        c = y;
        par.resize(n+2);
        len.assign(n+2, 1);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }
    bool join(int a, int b) {
        a = fin(a); b = fin(b);
        if(a == b) return false;
        if(rng() % 2) swap(a, b);
        if(c && len[a] < len[b])
            swap(a, b);
        par[b] = a;
        if(c) len[a] += len[b];
        return true;
    }
    int sz(int x) { return len[fin(x)]; }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    UFDS dsu; dsu.init(n);
    vector<array<int, 2>> x(n), y(n);
    vector<array<int, 3>> ed;
    for(int i = 0; i < n; i++) {
    	cin >> x[i][0] >> y[i][0];
    	x[i][1] = y[i][1] = i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 1; i < n; i++) {
    	ed.push_back({x[i][0] - x[i - 1][0], x[i][1], x[i - 1][1]});
    	ed.push_back({y[i][0] - y[i - 1][0], y[i][1], y[i - 1][1]});
    }
    sort(ed.begin(), ed.end());
    int ans = 0;
    for(auto edge : ed) {
    	int w = edge[0], u = edge[1], v = edge[2];
    	if(dsu.join(u, v)) ans += w;
    }
    cout << ans << '\n';
    return 0;
}