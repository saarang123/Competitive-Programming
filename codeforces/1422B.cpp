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

#define int long long
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    for(i = 1; i <= (n +  1)/2; i++) {
        for(j = 1; j <= (m + 1)/2; j++) {
            int mx = 1e15;
            vector<int> tmp = {a[i][j]};
            if(n - i + 1 != i) tmp.pb(a[n - i + 1][j]);
            if(m - j + 1 != j) tmp.pb(a[i][m - j + 1]);
            if(n - i + 1 != i && m - j + 1 != j) tmp.pb(a[n - i + 1][m - j + 1]);
            for(int x : tmp) {
                int mn = 0;
                for(int y : tmp) mn += abs(y - x);
                remin(mx, mn);
            }
            ans += mx;
        }
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
