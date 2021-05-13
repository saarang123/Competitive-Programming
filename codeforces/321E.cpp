#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar();
        }
    return x;
}

const int N = 4002, K = 803;
int a[N][N], p[N][N];
ll dp[K][N];

ll cost(int l, int r) {
	return (p[r][r] - p[r][l - 1] - p[l - 1][r] + p[l - 1][l - 1]) >> 1;
}

void fix(int i, int l, int r, int optl, int optr) {
	if(l > r)
		return;
	int m = (l + r) >> 1;
	array<ll, 2> best = {2000000000, -1};
	for(int j = optl; j <= min(m, optr); j++)
		best = min(best, {dp[i - 1][j] + cost(j + 1, m), j});
	dp[i][m] = best[0];
	int opt = best[1];
	fix(i, l, m - 1, optl, opt);
	fix(i, m + 1, r, opt, optr);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n = scan();
    int k = scan();
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= n; j++) {
    		a[i][j] = scan();
    		p[i][j] = a[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    	}
    }
    memset(dp[0], 0x7f, sizeof dp[0]);
    dp[0][0] = 0;
    for(int i = 1; i <= k; i++)
    	fix(i, 1, n, 0, n);
    cout << dp[k][n] << '\n';
    return 0;
}