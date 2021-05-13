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
// 7
// 1 2 2 3 4 2 2

void solve_case() {
    int n; cin >> n;
    vector<int> a(n), cnt[n + 1];
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    	reverse(all(cnt[i]));
    int ans = 1;
    array<int, 2> last = {a[0], 0};
    cnt[0].push_back(n);
   	cnt[a[0]].pop_back();
    for(int i = 1; i < n; i++) {
    	cnt[a[i]].pop_back();
    	if(a[i] == last[0] && a[i] == last[1])
    		continue;
    	ans++;
    	if(a[i] != last[0] && a[i] != last[1]) {
    		if((cnt[last[0]].empty() ? 0 : cnt[last[0]].back()) < (cnt[last[1]].empty() ? 0 : cnt[last[1]].back()))
    			last[0] = a[i];
    		else
    			last[1] = a[i];
    	} else if(a[i] == last[0])
    		last[1] = a[i];
    	else if(a[i] == last[1])
    		last[0] = a[i];
    }
    cout << ans << '\n';
}
