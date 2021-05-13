#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    	freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
	#endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n; cin >> n;
    vector<int> a(n), d(n), ans(n);
    int sum = 0;
    multiset<array<int, 2>> st;
    for(int &x : a) cin >> x, sum += x;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v; u--; v--;
    	d[u]++; d[v]++;
    }
    ans[0] = sum;
    for(int i = 0; i < n; i++) {
    	if(d[i] > 1)
    		st.insert({-a[i], d[i] - 1});
    }
    for(int i = 1; i < n - 1; i++) {
    	auto x = *st.begin();
    	sum += (-x[0]);
    	ans[i] = sum;
    	st.erase(st.begin());
    	if(x[1] > 1) st.insert({x[0], x[1] - 1});
    }
    for(int i = 0; i < n - 1; i++) cout << ans[i] << ' '; cout << '\n';
}
