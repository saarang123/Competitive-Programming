#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Line {
	mutable long long k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(long long x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const long long inf = LLONG_MAX;
	long long div(long long a, long long b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(long long k, long long m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	long long query(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int mxn = 100 * 1000 + 2;
int a[mxn], b[mxn], dp[mxn];
vector<int> g[mxn];

LineContainer dfs(int v, int p) {
	LineContainer node;
	for(int u : g[v]) if(u != p) {
		LineContainer child = dfs(u, v);
		if(child.size() > node.size())
			swap(node, child);
		for(auto l : child)
			node.add(l.k, l.m);
	}
	if(!node.empty())
		dp[v] = -node.query(a[v]);
	node.add(-b[v], -dp[v]);
	return node;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    for(int i = 1; i <= n; i++)
    	cin >> b[i];
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++)
    	cout << dp[i] << ' ';
    cout << '\n';
    return 0;
}