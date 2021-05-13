#include <bits/stdc++.h>
using namespace std;
const int mxn = 1003;
int a[mxn], id[mxn], n, m, idx;
vector<int> g[mxn], gt[mxn], tree[mxn], c[mxn], order;
vector<bool> used;
void topo(int v) {
	used[v] = true;
	for(int u : g[v]) if(!used[u]) topo(u);
	order.push_back(v);
}

void dfs(int v) {
	c[idx].push_back(a[v]);
	id[v] = idx;
	used[v] = true;
	for(int u : gt[v]) if(!used[u]) dfs(u);
}

int lis(vector<int> &aa) {
    vector<int> cnt;
    for(int x : aa) {
        int pos = lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin();
        if(pos == cnt.size()) cnt.push_back(x);
        else cnt[pos] = x;
    }
    return cnt.size();
}

int f(int v, int p, vector<int> l) {
    for(int x : c[v])
        l.push_back(x);
    int ret = lis(l);
    for(int u : tree[v]) if(u != p) {
        ret = max(ret, f(u, v, l));
    }
    return ret;
}


signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    used.resize(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	gt[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) if(!used[i]) topo(i);
    reverse(order.begin(), order.end());
    used.assign(n + 1, false);
    for(int i : order) 
    	if(!used[i]) {
    		++idx;
    		dfs(i);
    	}
    for(int v : order) {
    	for(int u : g[v]) 
    		if(id[v] != id[u])
    			tree[id[v]].push_back(id[u]);
    }
    for(int i = 1; i <= idx; i++) 
    	sort(c[i].begin(), c[i].end());
    int ans = 0;
    for(int i = 1; i <= idx; i++)
        ans = max(ans, f(i, -1, {}));
    cout << ans << '\n';
    return 0;
}