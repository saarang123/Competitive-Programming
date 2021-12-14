#include <bits/stdc++.h>
using namespace std;
const int MXN = 300 * 1000 + 3, LGN = 20;
int up[MXN][LGN], dt[MXN], tin[MXN];
int used[MXN], done[MXN], ok[MXN], has[MXN];
int n, k, tx = 0;
vector<int> g[MXN];

void dfs(int v = 1, int p = -1) {
	tin[v] = ++tx;
	for(int i = 1; i < LGN; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(int u : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		up[u][0] = v;
		dfs(u, v);
	}
}

int kth(int v, int d) {
	for(int i = 0; i < LGN; i++)
		if(d >> i & 1)
			v = up[v][i];
	return v;
}

int lca(int a, int b) {
	if(dt[a] > dt[b])
		swap(a, b);
	int c = kth(b, dt[b] - dt[a]);
	if(a == c)
		return a;
	for(int i = LGN - 1; i >= 0; i--) 
		if(up[a][i] != up[c][i]) {
			a = up[a][i]; c = up[c][i];
		}
	return up[a][0];
}
    
int dist(int a, int b) { return dt[a] + dt[b] - 2 * dt[lca(a,b)]; }

void colour(int v, int p) {
	used[v] = done[v];
	ok[v] = 0;
	has[v] = done[v];
	for(int u : g[v]) if(u != p) {
		colour(u, v);
		ok[v] += has[u];
		has[v] = has[v] || has[u];
	}
}

void reroot(int v, int p) {
	cout << v - 1 << ' ' << ok[v] << endl;
	if(done[v] || ok[v] >= 2)
		used[v] = true;
	for(int u : g[v]) if(u != p) {
		ok[v] += -ok[u] + has[v];
		ok[u] += ok[v];
		reroot(u, v);
		ok[u] -= ok[v];
		ok[v] += ok[u] - has[v];
	}
}

bool check(int length) {
	for(int l = length - 1; l < n; l++) {
		vector<int> lol;
		for(int i = 1; i <= n; i++) {
			done[i] = ok[i] = 0;
		}
		for(int j = 0; j < length; j++) {
			lol.push_back(l - j + 1);
			done[l - j + 1] = true;
		}
		cout << "aaaa\n";
		for(int x : lol)
			cout << x - 1 << ' ';
		cout << '\n';
		colour(1, -1);
		for(int i = 1; i <= n; i++)
			cout << ok[i] << ' ';
		cout << '\n';
		reroot(1, -1);
		for(int i = 1; i <= n; i++)
			cout << used[i] << ' ';
		cout << '\n';
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			cnt += used[j];
			used[j] = 0;
		}
		cout << "dist: " << cnt << '\n';
		if(cnt <= k)
			return true;
	}
	return false;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k;
    for(int u, v, i = 0; i < n - 1; i++) {
    	cin >> u >> v;
    	u++, v++;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs();
    // for(int i = 1; i <= n; i++) 
    // 	cout << tin[i] << ' ';
    // cout << '\n';
    //check(n);
    int mn = 1, mx = k;
    while(mn < mx) {
    	int mid = (mn + mx + 1) >> 1;
    	//cout << mn << ' ' << mid << ' ' << mx << endl;
    	if(check(mid))
    		mn = mid;
    	else
    		mx = mid - 1;
    }
    cout << mn << '\n';
    return 0;
}