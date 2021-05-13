#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 503;
int dp[N][N], f[N][N];
vector<int> a[N];

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m,k;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        a[i].pb(0);
        f[i][0] = 1e8;
        for(j = 1; j <= m; j++) {
            char c; cin >> c;
            if(c == '1') a[i].pb(j);
            f[i][j] = 1e8;
        }
    }
    for(i = 1; i <= n; i++) for(j = 0; j <= k; j++) dp[i][j] = 1e8;
    for(i = 1; i <= n; i++) {
        for(j = 1; j < a[i].size(); j++) {
            for(int l = j; l < a[i].size(); l++) {
                int cnt = a[i].size() - (l - j + 1) - 1;
                remin(f[i][cnt], a[i][l] - a[i][j] + 1);
                //if(cnt == 0) cout << a[i][l] << " " << a[i][j] << "\n";
            }
        }
        f[i][int(a[i].size()) - 1] = 0;
    }
    /*for(i = 1; i <= n; i++) {
        for(j = 0; j < a[i].size(); j++) cout << f[i][j] << " "; cout << "\n";
    }*/
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            for(int l = 0; l <= j; l++) {
                remin(dp[i][j], f[i][l] + dp[i-1][j-l]);
            }
        }
    }
    int ans = 1e8;
    for(i = 0; i <= k; i++) remin(ans, dp[n][i]);
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
