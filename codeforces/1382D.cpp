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

const int N = 4003;
bool dp[N][N];
int cnt[N];
int a[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i=1; i<=2*n; i++) cin >> a[i];
    for(i=1; i<=2*n; i++) cnt[i] = 0;
    int mx = -1, c = 0;
    for(i=1; i<=2*n; i++) {
        if(remax(mx, a[i]))
            cnt[++c] = 1;
        else
            cnt[c]++;
    }
    //for(i=1; i<=c; i++) cout << cnt[i] << " \n"[i==c];
    for(i=0; i<=2*n; i++) for(j=0; j<=2*n; j++) dp[i][j] = false;
    for(i=0; i<=2*n; i++) dp[i][0] = true;
    for(i=1; i<=c; i++) {
        for(j=1; j<=n; j++) {
            if(j < cnt[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-cnt[i]];
        }
    }
    if(dp[c][n]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0); std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
