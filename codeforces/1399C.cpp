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

void solve_case() {
    int n,i,j;
    cin >> n;
    int f[n*2+2];
    for(i=0; i<=n*2; i++) f[i] = 0;
    for(i=1; i<=n; i++) {
        int w;
        cin >> w;
        f[w]++;
    }
    int ans = -1;
    for(i=1; i<=n*2; i++) {
        int tmp = 0;
        for(j=1; j<=i; j++) {
            tmp += min(f[j], f[i-j]);
        }
        //cout << i << " "  << tmp << "\n";
        remax(ans, tmp);
    }
    cout << ans/2 << "\n";
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
