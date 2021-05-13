#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int query (vector<int> V); //Do not change this line
//You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the findHiddenVertex() function.

//Do not change the following function signature
vector<vector<int>> g, dt;
vector<int> tin;
int to_find = -1;

void init(int v = 1, int p = -1, int d = 0) {
	tin[v] = ++tin[0];
	dt[d].push_back(v);
	for(int u : g[v]) if(u != p)
		init(u, v, d + 1);
}

int dfs(int v, int p, int d) {
	if(v == to_find)
		return d;
	int res = 0;
	for(int u : g[v]) if(u != p)
		res = max(res, dfs(u, v, d + 1));
	return res;
}

int findHiddenVertex(int n, vector<int> parents){
	//Your code here.  For example
	// int h = query({2, 3, 5})
	g.assign(n + 1, {});
	dt.assign(n + 1, {});
	tin.assign(n + 1, 0);
	for(int i = 0; i < n - 1; i++) {
		g[i + 2].push_back(parents[i]);
		g[parents[i]].push_back(i + 2);
	}
	init();
	int h = query({1}) / 2;
	vector<int> s = dt[h];
	sort(s.begin(), s.end(), [&] (int x, int y) {
		return tin[x] < tin[y];
	});
	function<int(vector<int> &a)> solve = [&] (vector<int> &a) {
		if(a.size() == 1)
			return a.back();
		sort(a.begin(), a.end(), [&] (int x, int y) {
			return tin[x] < tin[y];
		});
		vector<int> q;
		for(int i = 0; i < a.size() / 2; i++)
			q.push_back(a[i]);
		to_find = q.back();
		int dist = dfs(a[0], -1, 0);
		if(query(q) <= dist)
			return solve(q);
		q.clear();
		for(int i = a.size() / 2; i < a.size(); i++)
			q.push_back(a[i]);
		return solve(q);
	};
	return solve(s);
}