//submitted by saarang123
#include <bits/stdc++.h>
//#include "examhalls.h"
using namespace std;
const long long MXN = 50 * 1000 + 3, inf = 1e10;

long long examhalls(int N, int A[]) {
    int n = N;
    vector<long long> a(n + 1), pref(n + 1);
    vector<vector<long long>> dp(2, vector<long long>(MXN, inf));
    //dp[i][j] - answer for first i indexes such that first group sums up to j (i.e other one is sum of first i elements - j)
    for(long long i = 1; i <= n; i++) a[i] = A[i - 1], pref[i] = pref[i - 1] + a[i];
    dp[0][0] = 0;
    for(long long i = 1, j = 0; i <= n; i++, j ^= 1) {
        for(long long s = 0; s <= pref[i]; s++) {
            if(pref[i - 1] - s >= 0) //giving ith element to second group
                dp[i & 1][s] = dp[j][s] - (pref[i - 1] - s) * (pref[i - 1] - s) + (pref[i] - s) * (pref[i] - s);
            if(s - a[i] >= 0) //giving ith element to first group
                dp[i & 1][s] = min(dp[i & 1][s], dp[j][s - a[i]] - (s - a[i]) * (s - a[i]) + s * s);
        }
    }
    long long ans = pref[n] * pref[n];
    for(long long i = 0; i < MXN; i++) ans = min(ans, dp[n & 1][i]);
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    cout << examhalls(n, A);
    return 0;
}
