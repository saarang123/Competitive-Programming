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

const int X = 10 * 1000 * 1000 + 2;
int spf[X];
void sieve() {
	spf[1] = 1;
    for (int i=2; i<X; i++)
        spf[i] = i;
    for (int i=4; i<X; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<X; i++) {
        if (spf[i] == i) {
            for (int j=i*i; j<X; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    sieve();
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) {
    	cin >> x;
    	map<int, int> cnt;
    	int p = 1;
    	while(x != 1) {
    		cnt[spf[x]]++;
    		x /= spf[x];
    	}
    	for(auto &[r, f] : cnt)
    		if(f & 1)
    			p *= r;
    	x = p;
    }
    int ans = 0;
    set<int> seen;
    for(int i = 0; i < n; i++) {
    	if(seen.count(a[i])) {
    		ans++;
    		seen.clear();
    	}
    	seen.insert(a[i]);
    }
    ans += !seen.empty();
    cout << ans << '\n';
}
