#include <bits/stdc++.h>
using namespace std;
const int MXN = 2003;
const int MXM = 200 * 1000 + 3;
int h, w, p, q;
string g[MXN];
int closest[MXN][MXN], dist[MXN][MXN], ans[MXM], par[MXM], sz[MXM];
vector<array<int, 3>> edge;
set<int> qry[MXM];
 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
 
bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < h && y < w && !closest[x][y] && g[x][y] != '#';
}
 
int find(int a) {
    return a == par[a] ? a : par[a] = find(par[a]);
}
 
void join(int a, int b, int W) {
	a = find(a); b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) 
		swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    if(qry[a].size() < qry[b].size()) 
    	swap(qry[a], qry[b]);
    for(auto x : qry[b]) {
        if(qry[a].count(x)) {
            ans[x] = W;
            qry[a].erase(x);
        } else {
            qry[a].insert(x);
        }
    }
    qry[b].clear();
}
 
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin >> h >> w >> p >> q;
    for(int i = 0; i < h; i++) {
        cin >> g[i];
    }
 
    queue<array<int, 2>> qq;
    memset(ans, -1, sizeof ans);
 
    for(int u, v, i = 1; i <= p; i++) {
        cin >> u >> v;
        --u, --v;
        closest[u][v] = i;
        qq.push({u, v});
    }
 
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        qry[a].insert(i);
        qry[b].insert(i);
    }
 
    iota(par, par + p + 1, 0);
    fill(sz, sz + p + 1, 1);
 
    while(!qq.empty()) {
        auto [x, y] = qq.front();
        qq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ok(nx, ny)) {
                closest[nx][ny] = closest[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                qq.push({nx, ny});
            }
        }
    }
 
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(i + 1 < h && closest[i][j] != closest[i + 1][j]) {
                int a = closest[i][j];
                int b = closest[i + 1][j];
                if(a != 0 && b != 0) {
                    int W = dist[i][j] + dist[i + 1][j];
                    edge.push_back({W, a, b});
                }
            }
            if(j + 1 < w && closest[i][j] != closest[i][j + 1]) {
                int a = closest[i][j];
                int b = closest[i][j + 1];
                if(a != 0 && b != 0) {
                    int W = dist[i][j] + dist[i][j + 1];
                    edge.push_back({W, a, b});
                }
            }
        }
    }
 
    sort(edge.begin(), edge.end());
    for(auto [W, a, b] : edge) {
        join(a, b, W);
        if (sz[find(1)] == p) break;
    }
 
    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
 
    return 0;
}