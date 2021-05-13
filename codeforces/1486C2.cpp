#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


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
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
int qry(int l, int r) {
	if(l == r) return -1;
	cout << "? " << l << ' ' << r << '\n';
	cout.flush();
	int x; cin >> x;
	return x;
}

void solve_case() {
	int n;
	cin >> n;
	int a = qry(1, n);
	int f = qry(1, a);
	int g = qry(a, n);
	if(f == a) {
		int pos = a;
		for(int z = 1<<17; z>>=1;)
			if(pos-z > 0 && qry(pos-z, a) != a) pos -= z;
		cout << "! " << --pos << endl;
	} else {
		int pos = a;
		for(int z = 1<<17; z>>=1;)
			if(pos+z < n && qry(a, pos+z) != a) pos += z;
		cout << "! " << ++pos << endl;
	}
	cout.flush();
}
