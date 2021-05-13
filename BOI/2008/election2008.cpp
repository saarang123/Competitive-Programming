#include <bits/stdc++.h>
using namespace std;
const int mxn = 302, mxa = 100 * 1000 + 2;
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
    int sum = 0;
    for(int i = 1; i <= n; i++)
    	cin >> a[i], sum += a[i];
    vector<vector<int>> dp(n + 1, vector<int> (mxa + 3, -100000000));
    dp[0][0] = 100000000;
    for(int i = 1; i <= n; i++) {
    	for(int j = 0; j < mxa; j++)
    		dp[i][j] = dp[i - 1][j];
    	for(int j = 0; j < mxa; j++) 
    		if(j + a[i] < mxa)
    			dp[i][j + a[i]] = max(dp[i][j + a[i]], min(a[i], dp[i - 1][j]));
    }
    int ans = 0;
    for(int j = 0; j < mxa; j++)
    	if(2 * j > sum && 2 * (j - dp[n][j]) <= sum)
    		ans = max(ans, j);
    vector<int> id;
    function<void(int i, int j)> out = [&] (int i, int j) {
    	if(i < 1 || j == 0) 
    		return;
    	if(dp[i][j] == dp[i - 1][j])
    		out(i - 1, j);
    	else {
    		id.push_back(i);
    		out(i - 1, j - a[i]);
    	}
    };
    out(n, ans);
    cout << id.size() << '\n';
    reverse(id.begin(), id.end());
    for(int x : id)
    	cout << x << ' ';
    cout << '\n';
    return 0;
}