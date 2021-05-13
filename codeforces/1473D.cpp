#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
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
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    s  = " " + s;
    vector<int> pref(n + 1);
    vector<array<int, 2>> a(n + 1), b(n + 2);
    int mn = 0, mx = 0, x = 0;
    for(int i = 1; i <= n; i++) {
    	if(s[i] == '+') x++;
    	else x--;
    	mn = min(mn, x); mx = max(mx, x);
    	pref[i] = x;
    	a[i] = {mn, mx};
    }
    for(int i = n; i; i--) {
    	if(s[i] == '+') {
    		b[i] = {min(0, b[i + 1][0] + 1), b[i + 1][1] + 1};
    	} else {
    		b[i] = {b[i + 1][0] - 1, max(0, b[i + 1][1] - 1)};
    	}
    }
    while(m--) {
    	int l, r;
    	cin >> l >> r;
    	auto left = a[l - 1], right = b[r + 1];
    	auto t = pref[l - 1];
    	array<int, 2> range = {min(left[0], t + right[0]), max(left[1], t + right[1])};
    	cout << (range[1] - range[0] + 1) << '\n';
    }
}
