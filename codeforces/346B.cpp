#include <bits/stdc++.h>
using namespace std;

template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int N = 102;
int dp[N][N][N], cnt[N][30];
//dp[i][j][k] - answer for first i of s1, j of s2 and k as substring of virus
//cnt[i][j] - if i make virus[i] as character j, what is the size of the substring of virus?
array<int, 3> p[N][N][N];
int n, m, t;
string s1, s2, virus;

int f(int i, int j, int k) {
    if(k >= t) return -N;
    if(i >= n || j >= m) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(s1[i] == s2[j]) {
        if(s1[i] == virus[k]) {
            dp[i][j][k] = 1 + f(i + 1, j + 1, k + 1);
            p[i][j][k] = {i + 1, j + 1, k + 1};
        } else {
            dp[i][j][k] = 1 + f(i + 1, j + 1, cnt[k][s1[i] - 'A']);
            p[i][j][k] = {i + 1, j + 1, cnt[k][s1[i] - 'A']};
        }
    }
    if(remax(dp[i][j][k], f(i + 1, j, k))) p[i][j][k] = {i + 1, j, k};
    if(remax(dp[i][j][k], f(i, j + 1, k))) p[i][j][k] = {i, j + 1, k};
    return dp[i][j][k];
}

string out(int i, int j, int k) {
    if(i == -1 || j == -1 || k == -1) return "";
    array<int, 3> id = p[i][j][k];
    if(id[0] == i + 1 && id[1] == j + 1) return s1[i] + out(id[0], id[1], id[2]);
    return out(id[0], id[1], id[2]);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> s1 >> s2 >> virus;
    n = s1.size(); m = s2.size(); t = virus.size();
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) for(int k = 0; k <= t; k++) {
        dp[i][j][k] = -1;
        p[i][j][k] = {-1, -1, -1};
    }
    string tmp = "", cur;
    for(int i = 0; i < t; i++) {
        tmp += virus[i];
        for(int c = 0; c < 26; c++) {
            cur = tmp;
            cur += ('A' + c);
            for(int j = 0; j <= i + 1; j++) {
                bool ok = 1;
                int l = 0;
                for(int k = j; k <= i + 1; k++) ok = ok && (cur[k] == virus[l++]);
                if(ok) {
                    cnt[i + 1][c] = max(cnt[i + 1][c], i + 2 - j);
                }
            }
        }
    }
    //for(int i = 0; i < t; i++) { for(int j = 0; j < 26; j++) cout << cnt[i][j] << ' '; cout << '\n'; }
    int ans = f(0, 0, 0);
    if(ans == 0) cout << 0 << '\n';
    else cout << out(0, 0, 0) << "\n";
    return 0;
}
