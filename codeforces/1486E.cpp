#include <bits/stdc++.h>
using namespace std;
template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
const int N = 1e5 + 3, W = 52, inf = 2e9;
int dt[N][W][2];
vector<array<int, 2>> g[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int u, v, w, _ = 0; _ < m; _++) {
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    for(int i = 0; i <= n; i++) 
    	for(int j = 0; j < W; j++)
    		for(int k = 0; k < 2; k++)
    			dt[i][j][k] = inf;
    min_pq<array<int, 4>> pq;
    dt[1][0][0] = 0;
    pq.push({0, 0, 1, 0});
    while(!pq.empty()) {
    	auto [wt, w1, v, p] = pq.top();
    	pq.pop();
    	for(auto [u, w2] : g[v]) {
    		array<int, 2> nxt = {wt + w2 * w2, w2};
    		if(p)
    			nxt[0] += 2 * w1 * w2;
    		if(nxt[0] < dt[u][w2][p ^ 1]) {
    			dt[u][w2][p ^ 1] = nxt[0];
    			pq.push({nxt[0], w2, u, p ^ 1});
    		}
    	}
    }
    for(int i = 1; i <= n; i++) {
    	int e = inf;
    	for(int j = 0; j < W; j++)
    		e = min(e, dt[i][j][0]);
    	cout << (e >= inf ? -1 : e) << ' ';
    }
    cout << '\n';
    return 0;
}