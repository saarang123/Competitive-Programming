#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
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

const int mxn = 5002;
int a[mxn], b[mxn], dp[2][mxn], p[mxn];
void solve_case() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= n; j++) {
        cin >> b[j];
        p[j] = p[j - 1] + b[j] * a[j];
    }
    int ans = p[n];
    for(int i = n; i; i--) {
        for(int j = i; j <= n; j++) {
            if(i == j) dp[i & 1][j] = a[i] * b[i];
            else
                dp[i & 1][j] = a[i] * b[j] + a[j] * b[i] + dp[(i & 1) ^ 1][j - 1];
            ans = max(ans, p[i - 1] + dp[i & 1][j] + p[n] - p[j]);
        }
    }
    cout << ans << '\n';
}
