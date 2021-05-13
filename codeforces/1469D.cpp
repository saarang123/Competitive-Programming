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

int ceil(int x, int y) { return (x + y - 1) / y; }

void solve_case() {
    int n; cin >> n;
    if(n == 3) {
    	cout << "2\n3 2\n3 2\n";
    	return;
    }
    int x = 3;
    for(; x <= n; x++) {
    	if(ceil(ceil(ceil(ceil(n, x), x), x), x) == 1)
    		break;
    }
    assert(x <= 22);
    vector<array<int, 2>> ans;
    for(int i = 1; i < n; i++) {
    	if(i > 2 && i != x) ans.push_back({i, n});
    }
    for(int i = 0; i < 4; i++) ans.push_back({n, x});
    for(int i = 0; i < 5; i++) ans.push_back({x, 2});
    assert(ans.size() <= n + 5);
	cout << ans.size() << '\n';
	for(auto tx : ans) cout << tx[0] << ' ' << tx[1] << '\n';
}
