#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, INF = 1e9;

struct SegmentTree {
	using T = array<int, 2>;
	const T ID = {-INF, -1}; T comb(T x, T y){ return max(x, y); }
	int n; vector<T> a;
	void init(int N) { a.assign((n = N)*2, ID); }
	void build() { for(int i = n - 1; --i; ) a[i] = comb(a[2 * i], a[2 * i +  1]); }
	void update(int i, T v) {
		for(a[i += n] = v; i /= 2; ) a[i] = comb(a[2 * i], a[2 * i + 1]); }
	T query(int l, int r){
		T lx = ID, rx = ID;
		for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if(l & 1) lx = comb(lx, a[l++]);
			if(r & 1) rx = comb(a[--r], rx);
		}
		return comb(lx, rx);
	}
} st;

vector<int> g[MAXN];
string s;
int p[MAXN], d[MAXN], tin[MAXN], tout[MAXN];
long long ans;
int tx;

void dfs(int u, int depth) {
	d[u] = depth;
	tin[u] = tx++;
	for(int v : g[u]) {
		dfs(v, depth + 1);
	}
	tout[u] = tx++;

	if(s[u] == '1') {
		st.update(tin[u], {d[u], u});
		st.update(tout[u], {d[u], u});
	} else {
		array<int, 2> x = st.query(tin[u], tout[u]);
		if(x[1] < 0) return;
		int par = p[x[1]];
		ans += x[0] - d[u];

		st.update(tin[x[1]], st.ID);
		st.update(tout[x[1]], st.ID);

		st.update(tin[par], {d[par], par});
		st.update(tout[par], {d[par], par});
	}
}

signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		cin >> s;

		for(int i = 0; i < n; ++i) g[i].clear();
		st.init(n + n);
		ans = 0;
		tx = 0;

		for(int i=1; i<n; ++i) cin >> p[i], g[--p[i]].push_back(i);
		dfs(0, 0);
		cout << ans << '\n';
	}
}