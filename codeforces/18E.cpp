#include <bits/stdc++.h>
using namespace std;

const int inf = 1000 * 1000 * 1000;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    vector<vector<int>> cost1(n + 1, vector<int>(26));
    vector<vector<int>> cost0(n + 1, vector<int>(26));
    for(int i = 1; i <= n; i++) {
        vector<int> c1(26, 0), c0(26, 0);
        for(int j = 1; j <= m; j++) {
            if(j & 1) c1[a[i][j] - 'a']++;
            else c0[a[i][j] - 'a']++;
        }
        for(int j = 0; j < 26; j++) {
            cost1[i][j] = (m + 1) / 2 - c1[j];
            cost0[i][j] = m / 2 - c0[j];
        }
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(26, vector<int>(26, 0)));
    vector<array<int, 3>> t;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == j) dp[1][i][j] = inf;
            else
                dp[1][i][j] = cost1[1][i] + cost0[1][j];
            t.push_back({dp[1][i][j], i, j});
        }
    }
    sort(t.begin(), t.end());
    for(int i = 2; i <= n; i++) {
        for(int c1 = 0; c1 < 26; c1++) {
            for(int c2 = 0; c2 < 26; c2++) {
                if(c1 == c2) {
                    dp[i][c1][c2] = inf;
                    continue;
                }
                for(array<int, 3> tx : t) {
                    if(tx[1] != c1 && tx[2] != c2) {
                        dp[i][c1][c2] = tx[0] + cost1[i][c1] + cost0[i][c2];
                        break;
                    }
                }
            }
        }
        t.clear();
        for(int c1 = 0; c1 < 26; c1++) for(int c2 = 0; c2 < 26; c2++) t.push_back({dp[i][c1][c2], c1, c2});
        sort(t.begin(), t.end());
    }
    int ans = inf;
    array<int, 2> colour;
    for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) {
        if(ans > dp[n][i][j]) {
            ans = dp[n][i][j];
            colour = {i, j};
        }
    }
    vector<string> flag;
    function<void(int id, int i, int j)> out = [&] (int id, int i, int j) {
        //cout << "inside out: " << id << " " << i << " " << j << endl;
        string tmp = "";
        for(int x = 1; x <= m; x++) {
            if(x & 1) tmp += ('a' + i);
            else tmp += ('a' + j);
        }
        flag.push_back(tmp);
        if(id == 1) return;
        for(int c1 = 0; c1 < 26; c1++) for(int c2 = 0; c2 < 26; c2++) {
            if(i == c1 || j == c2) continue;
            if(dp[id][i][j] == dp[id - 1][c1][c2] + cost1[id][i] + cost0[id][j])
                return void(out(id - 1, c1, c2));
        }
    };
    out(n, colour[0], colour[1]);
    reverse(flag.begin(), flag.end());
    cout << ans << endl;
    for(string row : flag) cout << row << endl;
    return 0;
}
