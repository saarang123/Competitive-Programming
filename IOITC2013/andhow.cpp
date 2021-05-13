#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve(int n, bool *ans) {
	bool q[n];
	memset(ans, false, sizeof ans);
	memset(q, true, sizeof ans);
	while(true) {
		int mn = 0, mx = n - 1;
		while(mn < mx) {
			int mid = (mn + mx) >> 1;
			for(int i = mn; i <= mid; i++) if(!ans[i])
				q[i] = false;
		}
	}
}

const int mxn = 25003;
bool ans[mxn], a[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int x, i = 0; i < k; i++) {
    	cin >> x;
    	a[x] = true;
    }
    return 0;
}