#include <bits/stdc++.h>
using namespace std;
const int N = 5002;
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
    vector<int> a(n), dp(n);
    for(int i = 0; i < n; i++) 
    	cin >> a[i];
    for(int i = 0; i < n; i++) {
    	dp[i] = 1;
    	for(int j = 0; j < i; j++)
    		if(a[i] - a[j] >= k)
    			dp[i] = max(dp[i], dp[j] + 1);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}