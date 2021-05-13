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
    int n; cin >> n;
    vector<int> a(2 * n + 2), f(2 * n + 3);
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	int x; cin >> x;
    	a[x]++;
    }
    for(int i = 1; i <= 2 * n; i++) {
    	if(f[i]) {
    		ans++;
    		f[i + 1] += (a[i] > 0);
    	} else if(a[i]) {
    		ans++; a[i]--;
    		f[i + 1] += (a[i] > 0);
    	}
    }
    ans += f[2 * n + 1];
    cout << ans << '\n';
}
