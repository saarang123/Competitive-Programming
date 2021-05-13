#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int mod = 1e9 + 7;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
        if(rng() % 2) swap(a, b);
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
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    UFDS dsu; dsu.init(m);
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
    	int a, b = 0, k;
    	cin >> k >> a; k--;
    	if(k) cin >> b;
    	if(dsu.join(a, b))
    		ans.push_back(i);
    }
    int c = 1;
    for(int _ = 0; _ < ans.size(); _++) (c += c) %= mod;
    cout << c << ' ' << ans.size() << '\n';
	for(int x : ans) cout << x << ' '; cout << '\n';
    return 0;
}