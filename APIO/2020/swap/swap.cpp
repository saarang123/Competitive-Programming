#include "swap.h"
#include <bits/stdc++.h>
using namespace std;

/*If offline was allowed, can be done with parallel binary search.
answer is -1 only for line tree, use a reachability tree to solve.
Works in O(log log n) per query.
Compile with :
problem=swap
g++ -std=c++17 -o "${problem}" "grader.cpp" "${problem}.cpp" -O2 -lm
*/

const int MXN = 100 * 1000 +3;
const int MXM = 200 * 1000 + 3;
const int LGN = 19;

int par[MXN + MXM], deg[MXN + MXM], cost[MXN + MXM], up[MXN + MXM][LGN], dt[MXN + MXM];
bool valid[MXN + MXM];
vector<int> g[MXN + MXM];
vector<array<int, 3>> ed;
int node;

void dfs(int v = node - 1, int p = node - 1) {
	up[v][0] = p;
	for(int i = 1; i < LGN; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(int u : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		dfs(u, v);
	}
}

int kth(int u, int difference) {
	for(int i = 0; i < LGN; i++)
		if(difference >> i & 1)
			u = up[u][i];
	return u;
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

int find(int v) {
	return par[v] == v ? v : par[v] = find(par[v]);
}

void unite(int u, int v, int w) {
	deg[u]++; deg[v]++;
	valid[node] = deg[u] >= 3 || deg[v] >= 3;

	u = find(u); v = find(v);
	g[node].push_back(u);

	if(u == v) {
		valid[node] = true;
		par[u] = node;
		cost[node++] = w;
		return;
	}

	g[node].push_back(v);
	par[v] = par[u] = node;
	cost[node] = w;
	valid[node] = valid[node] | valid[u] | valid[v];
	node++;
}

int query(int u) {
	if(valid[u])
		return cost[u];
	for(int i = LGN - 1; i >= 0; i--)
		if(!valid[up[u][i]])
			u = up[u][i];
	return valid[up[u][0]] ? cost[up[u][0]] : -1;
}

void init(int N, int M, std::vector<int> U, std::vector<int> V, std::vector<int> W) {
	for(int i = 0; i < M; i++)
		ed.push_back({W[i], U[i], V[i]});
	sort(ed.begin(), ed.end());
	iota(par, par + N + M, 0);
	node = N;

	for(auto edge : ed) {
		int u = edge[1], v = edge[2], w = edge[0];
		unite(u, v, w);
	}

	dfs();
}


int getMinimumFuelCapacity(int X, int Y) {
	return query(LCA(X, Y));
}
