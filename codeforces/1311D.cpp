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
const int N = 1e5;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,k;
    int a,b,c;
    cin >> a >> b >> c;
    n = 1e18;
    int f[3] = {0,0,0};
    for(i = 1; i <= 2*a; i++) {
        for(j = i; j <= 2*b; j += i) {
            for(k = j; k <= 2*c; k += j) {
                if(remin(n, abs(a - i) + abs(b - j) + abs(c - k))) {
                    f[0] = i, f[1] = j, f[2] = k;
                }
            }
        }
    }
    cout << n << "\n";
    cout << f[0] << " " << f[1] << " " << f[2] << "\n";
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
