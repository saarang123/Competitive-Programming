#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int query (vector<int> V); //Do not change this line
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenVertex() function.

//Do not change the following function signature
vector<vector<int>> g;
vector<int> cnt;

array<int, 2> dfs(int v = 1, int p = -1, int d = 0) {
	array<int, 2> ret = {d, v};
	for(int u : g[v]) if(u != p)
		ret = max(ret, dfs(u, v, d + 1));
	return ret;
}

int findHiddenVertex(int n, vector<int> parents){
	//Your code here.  For example
	// int h = query({2, 3, 5})
	g.assign(n + 1, {});
	cnt.assign(n + 1, 0);
	for(int i = 0; i < n - 1; i++) {
		g[i + 2].push_back(parents[i]);
		g[parents[i]].push_back(i + 2);
	}
	auto [l, a] = dfs();
	auto [diam, b] = dfs(a);
	int d1 = query({a}), d2 = query({b});
	if(!d1 || !d2)
		return !d1 ? a : b;
	int h = max(d1, d2) / 2;
	vector<int> s;
	for(int i = 1; i <= n; i++) if(i != a && i != b)
		s.push_back(i);
	function<int(vector<int> &q)> solve = [&] (vector<int> &q) {
		if(q.size() == 1)
			return q[0];
		vector<int> newQ[2];
		for(int i = 0; i < q.size(); i++)
			newQ[i & 1].push_back(q[i]);
		vector<int> toquery = newQ[0];
		toquery.push_back(a);
		toquery.push_back(b);
		int x = query(toquery);
		if(x == h)
			return solve(newQ[0]);
		return solve(newQ[1]);
	};
	shuffle(s.begin(), s.end(), rng);
	return solve(s);
}