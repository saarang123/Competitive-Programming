#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

const int og = 100000;
const int mxn = 203, mxm = 100 * 1000 + 5;
bool dp[mxn][mxm];
void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<long long, int>>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int t = a[i].first, y = a[i].second.second;
        long long x = a[i].second.first;
        for(int j = m; j >= 0; j--) {
            int X = ((x + og - 1) / og);
            if(dp[i - 1][j]) {
                if(t == 1)
                    for(int k = j, c = 0; k <= m && c <= y && !dp[i][k]; k += X, c++)
                        dp[i][k] = 1;
                else 
                    for(long long k = j, c = 0; k <= m && c <= y && !dp[i][k]; k = (k * x + og - 1LL) / og, c++)
                        dp[i][k] = 1;
            }

        }
    }
    for(int j = 1; j <= m; j++) {
        int ans = -1;
        for(int i = 1; i <= n; i++)
            if(dp[i][j]) {
                ans = i; break;
            }
        cout << ans << ' ';
    }
    cout << '\n';
}