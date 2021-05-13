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

const int N = 19;
ld dp[1<<N];
//dp[mask] - probability for situation with all the fish who's bit is 1 are left.
ld a[N][N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i=0; i<n; i++) for(j=0; j<n; j++) cin >> a[i][j];
    dp[(1<<n)-1] = 1;
    for(int mask = (1<<n)-1; mask; mask--) {
        int c = __builtin_popcount(mask);
        ld p = c*(c-1)/2;
        p = 1/p;
        for(i=0; i<n; i++) {
            if(mask & (1<<i)) {
                for(j=0; j<n; j++) {
                    if(i==j) continue;
                    if(mask & (1<<j))
                        dp[mask ^ (1<<j)] += (dp[mask] * p * a[i][j]);  //i eats j
                }
            }
        }
    }
    for(i=0; i<n; i++) cout << setprecision(8) << dp[1<<i] << " "; cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
