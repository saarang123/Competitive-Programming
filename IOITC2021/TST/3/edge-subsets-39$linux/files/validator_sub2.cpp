#include "testlib.h"
#include <vector>
#include <numeric>
using namespace std;

const int T = 1e3;
const int N = 100;
const int X = 1e5;
const int SN = 1e4;

vector<int> adj[N+1];
bool vis[N+1];
void dfs(int v){
	vis[v] = 1;
	for(auto i: adj[v])
		if(!vis[i])
			dfs(i);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, T, "t");
    inf.readEoln();
    int sum_n = 0, sum_m = 0;

    for(int it = 1; it <= t; it++) {
        setTestCase(it);

        int n = inf.readInt(1, N, "n"); inf.readSpace();
        int m = inf.readInt(0, N, "m"); inf.readEoln();
        sum_n += n;
        sum_m += m;
        ensuref(sum_n <= SN, "sum N limit exceeded");
        ensuref(sum_m <= SN, "sum M limit exceeded");

        for(int i = 0; i <= n; i++)
        {
        	adj[i].clear();
        	vis[i] = 0;
        }

        int p[n+1];
        for(int i = 2; i <= n; i++){
            p[i] = inf.readInt(1, n, "p[i]");
            ensuref(p[i] != i, "self loop");

            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);

            if(i < n) inf.readSpace();
            else inf.readEoln();
        }

        int c = 0;
        for(int i = 1; i <= n; i++){
        	if(!vis[i]){
        		c++;
        		dfs(i);
        	}
        }
        ensuref(c == 1, "not connected");

        for(int i = 1; i <= m; i++){
        	int u = inf.readInt(1, n, "u[i]"); inf.readSpace();
        	int v = inf.readInt(1, n, "v[i]"); inf.readSpace();
        	int l = inf.readInt(0, n-1, "l[i]"); inf.readSpace();
        	int r = inf.readInt(0, n-1, "r[i]"); inf.readEoln();
        	ensuref(l <= r, "l > r");
        	while(v != u and v != 1){
        	    v = p[v];
        	}
        	ensuref(v == u, "u not an ancestor of v");
        }
    }
    inf.readEof();
}
