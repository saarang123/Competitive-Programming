#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct BIT {
    int n;
    vector<int> bit;
    void init(int x) {
        n = x;
        bit.resize(n+2,0);
    }
    void init(vector<int> &a) {
        n = a.size();
        bit.resize(n+2, 0);
        for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1];
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
    int sum(int l, int r) { return qry(r) - qry(l-1); }
};

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.second.first < b.second.first;
}

const int N = 1e6+2;
map<int, int> key;
BIT bit;
vector<pair<int, pair<int, int>>> seg;
vector<int> coord;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    vector<int> ans(n);
    for(i=0; i<n; i++) {
        int l,r; cin >> l >> r;
        seg.pb(mp(l, mp(r, i)));
        coord.pb(l);
        coord.pb(r);
    }
    sort(all(coord));
    coord.resize(unique(all(coord)) - coord.begin());
    for(i=0; i<coord.size(); i++) {
        key[coord[i]] = i + 1;
    }
    bit.init(N);
    sort(all(seg), cmp);
    for(pair<int, pair<int, int>> point: seg) {
        int x = point.first, y = point.second.first, ind = point.second.second;
        ans[ind] = bit.sum(key[x], key[y]);
        bit.upd(key[x], 1);
    }
    for(int x: ans) cout << x << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
