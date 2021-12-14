#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 3003;
const int mod = 998244353;
int cnt[MXN][MXN], a[MXN], n, k;
ll dp[MXN], p[MXN];

ll sub() {
    ll ans = 1;
    for(int i = 1; i < n; i++, ans %= mod)
        ans <<= 1;
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == k || *max_element(a + 1, a + n + 1) == 1)
        return cout << sub() << '\n', 0;
    vector<vector<int>> big(n + 1);
    vector<vector<int>> pre(n + 1, vector<int>(11, -1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 10; j++)
            pre[i][j] = pre[i - 1][j];
        pre[i][a[i]] = i;
        vector<int> ord;
        for(int j = 1; j <= 10; j++) if(pre[i][j] > 0)
            ord.push_back(pre[i][j]);
        sort(ord.begin(), ord.end(), greater<>());
        cout << "indx: " << i << ' ' << a[i] << '\n';
        for(int x : ord)
            cout << x << ' ';
        cout << '\n';
        big[i] = ord;
    }

    dp[0] = p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1];
        for(int j = 1; j < min(k, int(big[i].size())); j++) {
            dp[i] += p[big[i][j - 1]] - p[big[i][j]] - dp[big[i][j - 1]] + dp[big[i][j]];
            dp[i] %= mod;
            dp[i] += mod;
            dp[i] %= mod;
        }
        if(big[i].size() <= k) {
            dp[i] += p[big[i].back() - 1];
            dp[i] %= mod;
        }
        p[i] += dp[i];
        p[i] %= mod;
        cout << dp[i] << ' ';
    }
    cout << '\n';
    cout << dp[n] << '\n';
    return 0;
}