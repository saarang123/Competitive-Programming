#include<bits/stdc++.h>
using namespace std;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool query (int i, int j); //Do not change this line
vector < pair <int, int> > init(); //Do not change this line

//You are free to add variables and functions at global scope here


//compile with g++ -DEVAL -std=gnu++17 -O2 -pipe -static -s -o CheckSCC grader_checkscc.cpp checkscc.cpp
//Do not change the following function signature

void solve (int n, int &res){
	vector<pair<int,int>> deg = init();
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&] (int i, int j) {
		return deg[i].first > deg[j].first;
	});
	vector<bool> vis(n);
	queue<int> q;
	q.push(a[0]);
	vis[a[0]] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u = 0; u < n && deg[v].second; u++) if(!vis[u]) {
			if(query(v + 1, u + 1)) {
				q.push(u);
				vis[u] = true;
				--deg[v].second;
			}
		}
	}
	res = accumulate(vis.begin(), vis.end(), 0) == n;
}