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
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
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
    string s; cin >> s;
    string t = "";
    int p = -1;
    for(int i = 0; i < n; i++) {
    	if(p == 2) {
    		if(s[i] == '0') t += "1";
    		else t += "0";
    		p = 1;
    	} else {
    		if(s[i] == '1') { t += "1"; p = 2;}
    		else {
    			if(p == 1) {t += "0"; p = 0;}
    			else { t += "1"; p = 1; }
    		}
    	}
    }
    cout << t << '\n';
}
