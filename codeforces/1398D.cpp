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

#define int long long
const int N = 203;
int a[N], b[N], c[N];
int dp[N][N][N];
void solve_case() {
    // :pray: :fishy: :orz:
    int na, nb, nc, i, j, k;
    cin >> na >> nb >> nc;
    for(i=1; i<=na; i++) cin >> a[i];
    for(i=1; i<=nb; i++) cin >> b[i];
    for(i=1; i<=nc; i++) cin >> c[i];
    sort(a, a+na+1);
    sort(b, b+nb+1);
    sort(c, c+nc+1);
    for(i=0; i<=na; i++) {
        for(j=0; j<=nb; j++) {
            for(k=0; k<=nc; k++){
                int &tmp = dp[i][j][k];
                if(i && j) remax(tmp, dp[i-1][j-1][k] + a[i]*b[j]);
                if(i && k) remax(tmp, dp[i-1][j][k-1] + a[i]*c[k]);
                if(j && k) remax(tmp, dp[i][j-1][k-1] + b[j]*c[k]);
            }
        }
    }
    cout << dp[na][nb][nc] << "\n";
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
