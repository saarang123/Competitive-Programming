#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
int f[2][mxn], cnt[2][mxn], a[mxn];
int n, q;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    f[0][n] = f[1][n] = -1;
    cnt[0][n] = cnt[1][n] = 1;
    for(int i = n - 1; i > 0; i--) {
    	f[0][i] = f[0][i + 1];
    	f[1][i] = f[1][i + 1];
    	cnt[0][i] = cnt[1][i] = 1;
    	if(f[0][i] > 0)
    		cnt[0][i] += cnt[1][f[0][i]];
    	if(f[1][i] > 0)
    		cnt[1][i] += cnt[0][f[1][i]];
    	if(a[i] > a[i + 1]) {
    		f[1][i] = i + 1;
    		cnt[1][i] = 1 + cnt[0][i + 1];
    	}
    	else {
    		f[0][i] = i + 1;
    		cnt[0][i] = 1 + cnt[1][i + 1];
    	}
    }
    while(q--) {

    }
    return 0;
}