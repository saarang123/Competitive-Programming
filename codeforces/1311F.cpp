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

#define int long long

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
};

map<int, int> key;
BIT freq, sum;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    vector<pair<int, int>> points(n);
    vector<int> v(n);
    freq.init(n);
    sum.init(n);
    for(i=0; i<n; i++) {
        cin >> points[i].first;
    }
    for(i=0; i<n; i++)
        cin >> points[i].second, v[i] = points[i].second;
    sort(all(points));
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());  //coordinate compressing
    for(i=0; i<v.size(); i++) {
        key[v[i]] = i+1;
    }
    int ans = 0;
    for(i=0; i<n; i++) {
        int index = key[points[i].second];
        int tmp = points[i].first * freq.qry(index) - sum.qry(index);
        //cout << points[i].first << " " << points[i].second << ": point" << "\n";
        //cout << index << " " << tmp << "\n------\n";
        ans += tmp;
        freq.upd(index, 1);
        sum.upd(index, points[i].first);
    }
    cout << ans << "\n";
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
