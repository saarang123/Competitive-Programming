#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 2000 * 1000 * 1000;
const int mxn = 1000 * 1000 + 2;
int dp[mxn][3]; //index, cur
int a[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
   		cin >> a[i];
   	auto convert = [&] (int x, int to, int add) {
   		int ans = 0;
   		for(int i = 0; i <= 3; i++) {
   			if(x == to)
   				return ans;
   			x += add;
   			ans++;
   		}
   		return inf;
   	};
   	memset(dp, 0x7f, sizeof dp);
   	dp[1][a[1] + 1] = 0;
   	for(int i = 2; i <= n; i++) {
   		for(int j = -1; j <= 1; j++)
   			for(int k = -1; k <= 1; k++)
   				if(j <= k) 
   					dp[i][k + 1] = min(dp[i][k + 1], dp[i - 1][j + 1] + convert(a[i], k, j));
   	}
   	int ans = min({dp[n][0], dp[n][1], dp[n][2]});
   	if(ans >= inf)
   		cout << "BRAK" << '\n';
   	else
   		cout << ans << '\n';
    return 0;
}