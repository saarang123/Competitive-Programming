#include <bits/stdc++.h>
using namespace std;
const int mxa = 2 * 1000 * 1000 + 3, mxn = 100 * 1000 + 3;
int spf[mxa];

void sieve() {
	for(int i = 1; i < mxa; i++) {
		if(i & 1)
			spf[i] = i;
		else
			spf[i] = 2;
	}
	for(int i = 3; i * i < mxa; i++) 
		if(spf[i] == i) 
			for(int j = i * i; j < mxa; j += i)
				if(spf[j] == j)
					spf[j] = i;
}

vector<int> fct(int x) {
	vector<int> decomp;
	while(x != 1) {
		decomp.push_back(spf[x]);
		x /= spf[x];
	}
	sort(decomp.begin(), decomp.end());
	decomp.resize(unique(decomp.begin(), decomp.end()) - decomp.begin());
	return decomp;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	vector<int> col(n + 1, -1), cnt(2 * n + 3);
	vector<vector<int>> pidx(mxa), g(n + 1);
	bool pos = true;
	for(int i = 1; i <= n && pos; i++) {
		vector<int> tmp = fct(a[i]);
		for(int p : tmp) {
			if(pidx[p].size() == 2) {
				pos = false; break;
			}
			for(int v : pidx[p]) {
				g[i].push_back(v);
				g[v].push_back(i);
			}
			pidx[p].push_back(i);
		}
	}
	function<bool(int v, int c)> dfs = [&] (int v, int c) {
		col[v] = c; cnt[c]++;
		for(int u : g[v]) {
			if(col[v] == col[u]) return false;
			if(col[u] == -1 && !dfs(u, c ^ 1))
				return false;
		}
		return true;
	};
	set<int> taken;
	for(int c = 0, v = 1; v <= n && pos; v++) if(col[v] == -1) {
		pos = dfs(v, c);
		if(cnt[c] >= cnt[c + 1]) taken.insert(c);
		else taken.insert(c + 1);
		c += 2;
	}
	if(!pos)
		return void(cout << -1 << '\n');
	vector<int> ans;
	for(int v = 1; v <= n; v++)
		if(taken.count(col[v]))
			ans.push_back(v);
	cout << ans.size() << '\n';
	for(int v : ans)
		cout << v << ' ';
	cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    sieve();
    int tc; cin >> tc;
    while(tc--) {
    	solve();
    }
    return 0;
}