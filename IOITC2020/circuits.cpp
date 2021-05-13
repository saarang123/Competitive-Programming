#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

const int MAXN = 1e5;
vector<vector<int>> g(MAXN), g1(MAXN), g2(MAXN);
vector<int> dfsNum(MAXN, 0), id(MAXN, -1), sz(MAXN, 0), st;

int dfsTimer = 1;

int tarjan(int u){
	int low = dfsNum[u] = dfsTimer++; st.push_back(u);
	for(int v : g[u])
		if(id[v]<0) low = min(low, dfsNum[v] ? : tarjan(v));
	if(low==dfsNum[u])
		for(int v=-1; v!=u; ++sz[u])
			id[v = st.back()] = u, st.pop_back();
	return low;
}

void topSort(int u, vector<int> &order){
	dfsNum[u] = 0;
	for(int v : g1[u]) if(dfsNum[v]) topSort(v, order);
	order.push_back(u);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef saarang
	freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
	freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
	#endif
	int n, m, x, y; cin >> n >> m;
	while(m--){
		cin >> x >> y;
		g[x-1].push_back(y-1);
	}
	for(int i=0; i<n; ++i) if(!dfsNum[i]) tarjan(i);

	for(int u=0; u<n; ++u)
		for(int v : g[u])
			if(id[u] != id[v]) g1[id[u]].push_back(id[v]), g2[id[v]].push_back(id[u]);

	vector<int> order;

	for(int i=0; i<n; ++i) if(dfsNum[i]) topSort(i, order);
	reverse(order.begin(), order.end());
	
	vector<int> dp1(n, -1e18), dp2(n, -1e18);
	int r = id[0];
	dp1[r] = dp2[r] = sz[r];
	n = order.size();

	for(int i=0; i<n; ++i){
		int u = order[i];
		for(int v : g1[u]){
			dp1[v] = max(dp1[v], dp1[u] + sz[v]);
		}
	}
	for(int i=n-1; i>=0; --i){
		int u = order[i];
		for(int v : g2[u]){
			dp2[v] = max(dp2[v], dp2[u] + sz[v]);
		}
	}

	int ans = sz[r];
	for(int u=0; u<n; ++u){
		for(int v : g[u]){
			if(id[u]==id[v]) continue;
			ans = max(ans, dp1[id[v]] + dp2[id[u]]);
		}
	}
	cout << ans-sz[r] << '\n';

}