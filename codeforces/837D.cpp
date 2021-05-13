#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 203;
array<int, 2> a[N];
int dp[2][N][N * 26];
int n, k;

int lg(int x, int y) {
    int c = 0;
    while(x % y == 0) {
        x /= y;
        c++;
    }
    return c;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k;
    int z = 1;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i][0] = lg(x, 2);
        a[i][1] = lg(x, 5);
        z += a[i][1];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int pw = 0; pw < z; pw++) {
                dp[1][j][pw] = max(dp[1][j][pw], dp[0][j][pw]); //dont pick
                if(j - 1 >= 0 && pw - a[i][1] >= 0 && dp[0][j - 1][pw - a[i][1]] != -1) //pick
                    dp[1][j][pw] = max(dp[1][j][pw], dp[0][j - 1][pw - a[i][1]] + a[i][0]);
            }
        }
        swap(dp[0], dp[1]);
        //memset(dp[1], -1, sizeof dp[1]);
    }
    int ans = 0;
    for(int i = 0; i < N * 26; i++) ans = max(ans, min(i, dp[0][k][i]));
    cout << ans << '\n';
    return 0;
}
