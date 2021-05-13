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
    string s, t;
    cin >> s >> t;
    n = s.size(); m = t.size();
    string ans = "-1";
    string a = "";
    for(int i = 1; i <= 20; i++) {
    	a += s; string b = "";
    	for(int j = 1; j <= 20; j++) {
    		b += t;
    		if(a == b) {
    			if(ans == "-1") ans = a;
    			else if(a.size() < ans.size()) ans = a;
    		}
    	}
    }
    cout << ans << '\n';
}
