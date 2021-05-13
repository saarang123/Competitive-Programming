#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("sse,sse2,avx,avx2")
#include <bits/stdc++.h>
using namespace std;

struct UFDS {
    int n, c;
    vector<int> len, par;
    void init(int x, int y = 1) {
        n = x;
        c = y;
        par.resize(n+2);
        len.assign(n+2, 1);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }
    bool join(int a, int b) {
        a = fin(a); b = fin(b);
        if(a == b) return false;
        if(c && len[a] < len[b])
            swap(a, b);
        par[b] = a;
        if(c) len[a] += len[b];
        return true;
    }
    int sz(int x) { return len[fin(x)]; }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m, k, idx = 0;
    cin >> n >> m >> k;
    vector<array<int, 4>> ed;
    for(int a, b, w, i = 0; i < m; i++) {
    	cin >> a >> b >> w;
    	ed.push_back({-w, a-1, b-1, i});
    }
    sort(ed.begin(), ed.end());
    vector<int> ans(m);
    vector<UFDS> uf(k);
    vector<vector<int>> nxt(n, vector<int>(n));
    for(int i = 0; i < k; i++)
    	uf[i].init(n);
    for(auto &[w, a, b, i] : ed) {
    	for(int j = nxt[a][b]; j < k; j++) {
    		if(uf[j].join(a, b)) {
    			ans[i] = j + 1;
    			nxt[a][b] = j + 1;
    			break;
    		}
    	}
    }
    for(int i = 0; i < m; i++)
    	cout << ans[i] << '\n';
    return 0;
}
