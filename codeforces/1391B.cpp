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

const int N = 103;
char a[N][N];
int vis[N][N];

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,m;
    cin >> n >> m;
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            vis[i][j] = 0;
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(a[i][j]=='D') vis[i+1][j]++;
            else if(a[i][j]=='U') vis[i-1][j]++;
            else if(a[i][j]=='R') vis[i][j+1]++;
            else if(a[i][j]=='L') vis[i][j-1]++;
        }
    }
    int sum = 0;
    for(i=1; i<=n; i++) for(j=1; j<=m; j++) sum += vis[i][j];
    ans = n*m - sum - 1;
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
