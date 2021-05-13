#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 2;
const ll inf = 1e15;
vector<int> a(102);
vector<array<bool, 2>> dp(N);
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = false, dp[0][1] = false;
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            if(i - a[j] < 0) continue;
            dp[i][0] = (dp[i][0] || !dp[i - a[j]][1]);
            dp[i][1] = (dp[i][1] || !dp[i - a[j]][0]);
        }
    }
    //for(int i = 0; i <= k; i++) cout << dp[i][0] << " " << dp[i][1] << endl;
    if(dp[k][0]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
