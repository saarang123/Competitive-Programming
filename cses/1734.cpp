#include <bits/stdc++.h>
using namespace std;
struct BIT {
    int n, lg;
    vector<int> bit;
    BIT() {}
    BIT(int _n) { init(_n); }
    BIT(vector<int> &a) { init(a); }
    void init(int x) {
        n = x; lg = 0;
        while(2 * (1 << lg) <= n) lg++;
        bit.resize(n + 2,0);
    }
    void init(vector<int> &a) {
        init(a.size());
        for(int i = 1; i <= n; i++) {
            bit[i] += a[i - 1]; //check this
            if(i + (i & -i) <= n)
                bit[i + (i & -i)] += bit[i];
        }
    }
    int qry(int x) {
        x = min(x, n);
        int ans = 0;
        for(; x > 0; x -= (x & -x))
            ans += bit[x];
        return ans;
    }
    int qry(int l, int r) { return qry(r) - qry(l - 1); }
    void upd(int x, int v) {
        if(x <= 0) return;
        for(; x <= n; x += (x & -x))
            bit[x] += v;
    }
    int lower_bound(int sum) {
        int x = 0;
        for(int k = lg; k >= 0; k--) {
            int nx = x + (1 << k);
            if(nx <= n && sum > bit[nx]) {
                x = nx;
                sum -= bit[x];
            }
        }
        return x + 1;
    }   
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    map<int,int> last;
    vector<int> a(n + 1);
    BIT bit(n);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    vector<array<int, 3>> queries(q);
    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
    	cin >> queries[i][0] >> queries[i][1]; queries[i][2] = i;
    }
    sort(queries.begin(), queries.end(), [&] (array<int, 3> &x, array<int, 3> &y) {
    	if(x[1] == y[1])
    		return x[0] < y[0];
    	return x[1] < y[1];
    });
    int i = 1;
    for(auto &[l, r, id] : queries) {
    	while(i <= r) {
    		if(last.count(a[i]))
    			bit.upd(last[a[i]], -1);
    		last[a[i]] = i;
    		bit.upd(i++, 1);
    	}
    	ans[id] = bit.qry(l, r);
    }
    for(i = 0; i < q; i++)
    	cout << ans[i] << '\n';
    return 0;
}