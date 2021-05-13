#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class T>
struct CoordinateCompression {
    std::vector<T> cmp;
    CoordinateCompression(std::vector<T> &a) {
        cmp = a;
        std::sort(cmp.begin(), cmp.end());
        cmp.resize(std::unique(cmp.begin(), cmp.end()) - cmp.begin());  //compressing element
    }
    int getL(T x) {  //index of closest element <= x
        int id = std::lower_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
        if(id >= cmp.size() || cmp[id] > x) id--;
        return id;
    }
    int getR(T x) {   //index of closest element > x
        int id = std::upper_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
        return id;
    }
};

struct BIT {
    int n;
    vector<int> bit;
    void init(int x) {
        n = x;
        bit.resize(n + 2,0);
    }
    void init(vector<int> &a) {
        n = a.size();
        bit.resize(n+2, 0);
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
    void upd(int x, int v) {
        if(x <= 0) return;
        for(; x <= n; x += (x & -x))
            bit[x] += v;
    }
    int qry(int l, int r) { return qry(r) - qry(l - 1); }
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    CoordinateCompression<int> cc(a);
    BIT bit; bit.init(n + 1);
    int ans = 0, id = 0;
    for(int sum : a) {
        int need = sum - t;
        ans += id - bit.qry(cc.getR(need));
        //cout << sum << ' ' << need << ' ' << cc.getR(need) << '\n';
        id++;
        bit.upd(cc.getR(sum), 1);
    }
    cout << ans << '\n';
    return 0;
}
