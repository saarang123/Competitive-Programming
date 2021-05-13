#include <bits/stdc++.h>
using namespace std;


void solve_case() {
    const int inf = 100 * 1000 * 1000;
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -1));
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    function<int(int id, int time)> f = [&] (int id, int time) {
        if(id > n) return 0;
        if(time > 2 * n) return inf;
        if(dp[id][time] != -1) return dp[id][time];
        return dp[id][time] = min(abs(a[id] - time) + f(id + 1, time + 1), f(id, time + 1));
    };
    cout << f(1, 1) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
