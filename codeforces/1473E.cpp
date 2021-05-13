#include <bits/stdc++.h>
using namespace std;
template<class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
const int N = 2e5 + 2;
const long long inf = 1e18;
vector<array<int, 2>> g[N];
long long dt[N][2][2];
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
    memset(dt, 0x7f, sizeof dt);
    min_pq<tuple<long long, int, bool, bool>> pq;
    dt[1][0][0] = 0;
    pq.push({0, 1, 0, 0});
    auto wadd = [&] (long long x, int v, bool a, bool b) {
    	if(x < dt[v][a][b]) {
    		dt[v][a][b] = x;
    		pq.push({x, v, a, b});
    	}
    };
    while(!pq.empty()) {
    	auto [f, v, add, sub] = pq.top();
    	pq.pop();
    	if(dt[v][add][sub] < f)
    		continue;
    	for(auto &[u, w] : g[v]) {
    		wadd(f + w, u, add, sub);
    		if(!add)
    			wadd(f + 2 * w, u, 1, sub);
    		if(!sub)
    			wadd(f, u, add, 1);
    		if(!add && !sub)
    			wadd(f + w, u, 1, 1);

    	}
    }
    for(int i = 2; i <= n; i++)
    	cout << dt[i][1][1] << ' ';
    cout << '\n';
    return 0;
}