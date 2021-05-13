#include <bits/stdc++.h>
using namespace std;
const string moo = "MOO", oom = "OOM";
bool win(vector<string> &board) {
	for(int i = 0; i < 3; i++) if(board[i] == moo || board[i] == oom) return true;
	for(int i = 0; i < 3; i++) {
		string o = "";
		o += board[0][i]; o += board[1][i]; o += board[2][i];
		if(o == moo || o == oom) return true;
	}
	string o = "";
	o += board[0][0]; o += board[1][1]; o += board[2][2];
	if(o == moo || o == oom) return true;
	o = "";
	o += board[0][2]; o += board[1][1]; o += board[2][0];
	if(o == moo || o == oom) return true;
	return false;
}

const int mxn = 28;
const vector<array<int, 2>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<string>> a(mxn, vector<string>(mxn));
vector<int> g[mxn];
vector<array<int, 2>> cell;
bool f[mxn][mxn];
int n, m, s, t;

bool dfs(int i, int j, int x, int y) {
	if(i < 0 || j < 0 || i >= n || j >= n) return false;
	if(i == x && j == y) return true;
	if((a[i][j] == "###" || a[i][j][0] == 'O' || a[i][j][0] == 'M') && (i != s || j != t)) return false;
	if(f[i][j]) return false;
	//cout << i << ' ' << j << " : " << x << ' ' << y << endl;
	f[i][j] = true;
	for(auto &[dx, dy] : dir) 
		if(dfs(i + dx, j + dy, x, y))
			return true;
	return false;
}

set<vector<string>> boards;

void fix(int v, vector<string> cur, vector<bool> vis) {
	if(vis[v]) return;
	string node = a[cell[v][0]][cell[v][1]];
	vis[v] = true;
	//cout << cell[v][0] << ' ' << cell[v][1] << endl;
	if(node[0] != 'B' && cur[node[1] - '0' - 1][node[2] - '0' - 1] == '.') 
		cur[node[1] - '0' - 1][node[2] - '0' - 1] = node[0];
	// for(int i = 0; i < 3; i++)
 //    		cout << cur[i] << '\n';
 //    	cout << '\n';
	//if(accumulate(vis.begin(), vis.end(), 0) == uf.sz(v)) return;
	if(win(cur)) {
		boards.insert(cur); return;
	}
	for(int i = 0; i < m; i++) if(vis[i])
	for(int u : g[i]) {
		fix(u, cur, vis);
	}
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n;
    array<int, 2> b;
    for(int i = 0; i < n; i++) 
    	for(int j = 0; j < n; j++) {
    		for(int k = 0; k < 3; k++) {
    			char c; cin >> c;
    			a[i][j] += c;
    		}
    		if(a[i][j][0] != '.' && a[i][j][0] != '#')
    			cell.push_back({i, j});
    		if(a[i][j] == "BBB") b = {i, j};
    	}
    // for(int i = 0; i < n; i++) {
    // 	for(int j = 0; j < n; j++) cout << a[i][j] << ' ';
    // 		cout << '\n';
    // }
    m = cell.size();
    //uf.init(m);
    for(int i = 0; i < m; i++) {
    	for(int j = 0; j < m; j++) if(i != j) {
    		memset(f, false, sizeof f);
    		s = cell[i][0]; t = cell[i][1];
    		if(dfs(cell[i][0], cell[i][1], cell[j][0], cell[j][1])) {
    			g[i].push_back(j);
    			//uf.join(i, j);
    		}
    	}
    }
    // for(int i = 0; i < m; i++) {
    // 	cout << cell[i][0] << ' ' << cell[i][1] << " is node: " << endl;
    // 	for(auto j : g[i])
    // 		cout << cell[j][0] << ' ' << cell[j][1] << " is connected" << endl;
    // }
    vector<bool> vis(m);	
    vector<string> cur(3, "...");
    for(int i = 0; i < m; i++) if(cell[i] == b) {
    	fix(i, cur, vis);
    }
    // for(auto board : boards) {
    // 	for(int i = 0; i < 3; i++)
    // 		cout << board[i] << '\n';
    // 	cout << '\n';
    // }
    cout << boards.size() << '\n';
    return 0;
}