#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 502;
int n, m;
vector<array<int, 3>> g[N][N];
int dt[N][N];

void add(int a, int b, int c, int d, int w) {
    g[a][b].pb({c, d, w});
    g[c][d].pb({a, b, w});
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int i, j;
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            char c; cin >> c;
            int dx = 0, dy = 0;
            if(c == '\\') dy = 1;
            else dx = 1;
            add(i, j, i + 1, j + 1, dx);
            add(i + 1, j, i, j + 1, dy);
        }
    }
    /*
    for(i = 0; i <= n + 1; i++)
    for(j = 0; j <= m + 1; j++) {
        cout << "graph: " << i << " " << j << endl;
        for(auto x : g[i][j]) cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }*/
    for(i = 0; i <= n + 1; i++) for(j = 0; j <= m + 1; j++) dt[i][j] = 1e9;
    set<pair<int, pair<int, int>>> pq;
    pq.insert(mp(0, mp(1, 1)));
    dt[1][1] = 0;
    while(!pq.empty()) {
        auto xx = *pq.begin(); pq.erase(pq.begin());
        int x = xx.second.first, y = xx.second.second;
        for(auto xy : g[x][y]) {
            int v = xy[0], u = xy[1], w = xy[2];
            if(dt[v][u] > dt[x][y] + w) {
                pq.erase(mp(dt[v][u], mp(v, u)));
                dt[v][u] = dt[x][y] + w;
                pq.insert(mp(dt[v][u], mp(v, u)));
            }
        }
    }
    //for(i = 1; i <= n + 1; i++) { for(j = 1; j <= m + 1; j++) cout << dt[i][j] << " "; cout << endl; }
    int ans = dt[n + 1][m + 1];
    if(ans >= 1e9) cout << "NO SOLUTION\n";
    else cout << ans << "\n";
    return 0;
}
