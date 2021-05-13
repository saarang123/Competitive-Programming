#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 203;
int dp[N][1 << 10];
int a[N], b[N];
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,m,k;
    cin >> n >> m;
    for(i=1; i<=n; i++) cin >> a[i];
    for(i=1; i<=m; i++) cin >> b[i];
    dp[0][0] = 1;
    for(i=1; i<=n; i++ ){
        for(j=1; j<=m; j++) {
            int tmp = a[i]&b[j];
            for(k=0; k<=(1<<9); k++) {
                if(dp[i-1][k]) {
                    dp[i][k|tmp] = 1;
                }
            }
        }
    }
    int ans = 1e9;
    for(i=0; i<=(1<<9); i++) if(dp[n][i]) ans = min(ans, i);
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
