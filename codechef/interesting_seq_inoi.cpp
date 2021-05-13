#include <bits/stdc++.h>
using namespace std;
const int N = 3002;
vector<int> g[N];
int n, l;
vector<int> dp;
vector<array<int, 2>> a;

void init() {
    for(int i = 0; i <= n; i++)
        g[i].clear();
    dp.clear();
    dp.assign(n, -1);
}

int dfs(int v) {
    if(dp[v] != -1)
        return dp[v];
    dp[v] = 1;
    for(int u : g[v]) {
        dp[v] = max(dp[v], 1 + dfs(u));
    }
    return dp[v];
}

bool check(int k) {
    init();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(abs(a[i][1] - a[j][1]) >= k) {
                if(a[i][0] == a[j][0])
                    return true;
                g[a[j][1]].push_back(a[i][1]);
            }
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(dp[i] == -1) 
            ans = max(ans, dfs(i));
    return ans >= l;
}

void solve() {
    cin >> n >> l;
    a.clear();
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i][0], a[i][1] = i;
    sort(a.begin(), a.end(), greater<>());
    int mn = 0, mx = n - 1;
    while(mn < mx) {
        int mid = (mn + mx + 1) >> 1;
        if(check(mid))
            mn = mid;
        else
            mx = mid - 1;
    }
    cout << mn << '\n';
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}