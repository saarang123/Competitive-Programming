#include "jumps.h"
#include <bits/stdc++.h>
using namespace std;

const int MXN = 200 * 1000 + 3;
vector<int> g[MXN];
vector<int> h;
int n;

void init(int N, std::vector<int> H) {
	n = N;
	h = H;
	stack<int> st;
	for(int i = 0; i < N; i++) {
		while(!st.empty() && h[st.top()] <= h[i])
			st.pop();
		if(!st.empty())
			g[i].push_back(st.top());
		st.push(i);
	}

	while(!st.empty())
		st.pop();
	for(int i = N - 1; i >= 0; i--) {
		while(!st.empty() && h[st.top()] <= h[i])
			st.pop();
		if(!st.empty())
			g[i].push_back(st.top());
		st.push(i);
	}
	
}

int minimum_jumps(int A, int B, int C, int D) {
	queue<int> q;
	int dt[n];
	memset(dt, -1, sizeof dt);
	for(int i = A; i <= B; i++) {
		dt[i] = 0;
		q.push(i);
	}
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		if(C <= v && v <= D)
			return dt[v];
		for(int u : g[v]) if(dt[u] < 0) {
			dt[u] = dt[v] + 1;
			q.push(u);
		}
	}
  	return -1;
}
