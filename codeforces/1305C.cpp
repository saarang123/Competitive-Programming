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
const int N = 2e5+2;
const int M = 1003;
int a[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n >> m;
    if(n > m) {
        cout << 0 << "\n";
        return;
    }
    for(i=1; i<=n; i++)
        cin >> a[i];
    int ans = 1;
    for(i=1; i<=n; i++) {
        for(j=i+1; j<=n; j++) {
            ans *= abs(a[i] - a[j]);
            ans %= m;
        }
    }
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
