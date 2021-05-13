#include <bits/stdc++.h>
using namespace std;
const int mxn = 10 * 1000 * 1000 + 200 * 1000;
const int inf = 2e9;
int dp[mxn], sub[mxn];
int m, q;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> m >> q;
    memset(dp, 0x7f, sizeof dp);
    vector<int> p(m);
    for(int i = 0; i < m; i++)
    	cin >> p[i];
    sort(p.begin(), p.end());
    dp[0] = 0;
    for(int i = 1; i < p.back(); i++)
    	dp[i] = 1;
    for(int i = 0; i < m; i++) 
    	for(int j = p[i] - 1; j < mxn; j += p[i])
    		sub[j] = max(sub[j], p[i] - 1);
    for(int i = mxn - 2; i >= 0; i--)
    	sub[i] = max(sub[i], sub[i + 1] - 1);
    for(int i = p.back(); i < mxn; i++)
    	dp[i] = min(dp[i], dp[i - sub[i]] + 1);
    while(q--) {
    	int n; cin >> n;
    	if(dp[n] >= inf) cout << "oo\n";
    	else cout << dp[n] << '\n';
    }
    return 0;
}