#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n;
    string s; cin >> s;
    n = s.size();
    s = "_" + s;
    vector<vector<bool>> pal(n + 5, vector<bool>(n + 5));
    for(int i = n; i > 0; i--) {
        for(int j = i; j <= n; j++) {
            if(i == j)
                pal[i][j] = true;
            else if(i == j - 1)
                pal[i][j] = s[i] == s[j];
            else if(s[i] == s[j])
                pal[i][j] = pal[i + 1][j - 1];
            else
                pal[i][j] = 0;
        }
    }
    vector<vector<int>> dp(n + 5, vector<int>(n + 5));
    for(int i = n; i > 0; i--) {
        for(int j = i; j <= n; j++) {
            if(i == j)
                dp[i][j] = 1;
            else 
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + pal[i][j];
        }
    }

    int q; cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
    return 0;
}