#include "roads.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MXN = 2003;
const ll inf = 1e14;
using vll = vector<vector<ll>>;
using vl = vector<ll>;
vector<array<int, 2>> g[MXN];
vector<vector<ll>> dp;
int deg[MXN];
int n;

void dfs(int v = 0, int p = -1) {
	vector<ll> t(n);
	int c = g[v].size() - 1;
	for(auto &[u, w] : g[v]) if(u != p) {
		dfs(u, v);
		vl ndp(n + 1, inf);
		for(int k = 0; k < n; k++) {
			for(int i = 0; i <= k; i++) {
				ndp[k] = min(ndp[k], dp[v][k] + w + dp[u][i]);
				if(i && k)
					ndp[k] = min(ndp[k], dp[v][k - 1] + dp[u][i - 1]);
			}
		}
		cout << "Node: " << v << " to " << u << '\n';
		for(int i = 0; i < n; i++)
			cout << ndp[i] << ' ';
		cout << '\n';
		swap(dp[v], ndp);
	}
	cout << "node: " << v << ' ' << c << endl;
	for(int i = 0; i < n; i++) 
		cout << dp[v][i] << ' ';
	cout << '\n';
}

std::vector<long long> minimum_closure_costs(int N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> W) {
	n = N;
	vector<ll> ans(n);
	for(int i = 0; i < N - 1; i++) {
		g[U[i]].push_back({V[i], W[i]});
		g[V[i]].push_back({U[i], W[i]});
		ans[0] += W[i];
	}
	dp = vector<vector<ll>>(n + 2, vector<ll>(n + 2));
	dfs();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	for(int i = 0; i < n; i++) {
		ans[i] = dp[0][i];
	}
  	return ans;
}
