#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5002;
const int inf = 1e15;
vector<vector<int>> dp(N, vector<int>(N));
int n, k, x;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k >> x;
    if(n / k > x)
        return cout << -1 << endl, 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= n; i++) dp[0][i] = -inf;
    for(int chosen = 1; chosen <= x; chosen++) {
        deque<pair<int, int>> rmq;  //max monotone queue
        rmq.push_front(make_pair(0, 0));
        for(int i = 1; i <= n; i++) {
            while(!rmq.empty() && (rmq.front().second < i - k)) rmq.pop_front();
            if(!rmq.empty()) dp[chosen][i] = rmq.front().first + a[i];
            else dp[chosen][i] = -inf;
            while(!rmq.empty() && rmq.back().first <= dp[chosen - 1][i]) rmq.pop_back();
            rmq.push_back(make_pair(dp[chosen - 1][i], i));
        }
    }
    int ans = 0;
    for(int i = n; i > n - k; i--) ans = max(ans, dp[x][i]);
    cout << ans << endl;
    return 0;
}
