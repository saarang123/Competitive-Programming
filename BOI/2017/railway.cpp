#include <bits/stdc++.h>
using namespace std;
const int MXN = 100 * 1000 + 3;
const int LGN = 19;
vector<int> g[MXN];
int nxt[MXN], up[MXN][LGN], dt[MXN], tin[MXN], p[MXN];
int n, m, k;

void dfs(int v = 1, int pp = 1) {
	up[v][0] = pp;
	tin[v] = ++tin[0];
	for(int i = 1; i < LGN; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(int u : g[v]) if(u != pp) {
		dt[u] = dt[v] + 1;
		dfs(u, v);
	}
}

int kth(int v, int diff) {
	for(int i = 0; i < LGN; i++)
		if(diff >> i & 1)
			v = up[v][i];
	return v;
}

int LCA(int u, int v) {
	if(dt[u] > dt[v])
		swap(u, v);
	v = kth(v, dt[v] - dt[u]);
	if(u == v)
		return u;
	for(int i = LGN - 1; i >= 0; i--)
		if(up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

int init(int v = 1, int pp = -1) {
	for(int u : g[v]) if(u != pp)
		p[v] += init(u, v);
	return p[v];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/code/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/code/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k;
    vector<array<int, 2>> ed(n - 1);
    for(auto &[u, v] : ed) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs();

    for(int i = 0; i < n - 1; i++) {
    	if(dt[ed[i][0]] < dt[ed[i][1]])
    		swap(ed[i][0], ed[i][1]);
    	nxt[ed[i][0]] = i + 1;
    }

    while(m--) {
    	int s; cin >> s;
    	vector<int> a(s);
    	for(int &x : a)
    		cin >> x;
    	sort(a.begin(), a.end(), [&] (int i, int j) {
    		return tin[i] < tin[j];
    	});
    	a.push_back(a[0]);

    	for(int i = 0; i < s; i++) {
    		p[a[i]]++;
    		p[a[i + 1]]++;
    		p[LCA(a[i], a[i + 1])] -= 2;
    	}
    }

    init();
    vector<int> answer;
    for(int i = 1; i <= n; i++)
    	if(p[i] >= 2 * k)
    		answer.push_back(nxt[i]);
    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for(int id : answer)
    	cout << id << ' ';
    cout << '\n';
    return 0;
}