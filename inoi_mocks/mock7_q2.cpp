#include <bits/stdc++.h>
using namespace std;

void compress(vector<int*> &coords) {
	int cnt = 0, prv = -1;
	sort(coords.begin(), coords.end(), [](int* x, int *y) {
		return *x < *y;
	});
	for(int i = 0; i < (int)coords.size(); ++i) {
		if(prv < *coords[i]) ++cnt;
		prv = *coords[i];
		*coords[i] = cnt;
	}
}

struct BIT {
    int n, lg;
    vector<int> bit;
    BIT() {}
    BIT(int _n) { init(_n); }
    BIT(vector<int> &a) { init(a); }
    void init(int x) {
        n = x; lg = 0;
        //while(2 * (1 << lg) <= n) lg++;
        bit.resize(n + 2, 0);
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
    void upd(int x, int v = 1) {
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
    int n, m, st;
    cin >> st >> n >> m;
    vector<int> a(n);
    vector<int*> coords;
    for(int &x : a) {
    	cin >> x;
    	coords.push_back(&x);
    }
    vector<array<int, 4>> q(m);
    for(auto &[t, l, r, v] : q) {
    	cin >> t >> l >> r;
    	l--, r--;
    	if(t == 1)
    		cin >> v;
    	if(t == 1) coords.push_back(&v);
    }
    
    int sz = coords.size();

    compress(coords);
    // for(auto x : coords)
    // 	cout << *x << ' ';
    // cout << '\n';
    // for(int i = 0; i < n; i++)
    // 	cout << a[i] << ' ';
    // cout << '\n';

    for(auto &[t, l, r, v] : q) {
    	if(t == 1) {
    		for(int i = l; i <= r; i++)
    			a[i] = v;
    	} else {
    		int ans = 0;
    		BIT bit; bit.init(sz);
    		for(int i = r; i >= l; i--) {
    			ans += bit.qry(a[i] - 1);
    			bit.upd(a[i]);
    		}
    		cout << ans << '\n';
    	}
    }
    return 0;
}