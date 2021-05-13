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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,t;
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0;
        for(i = 1; i < 10; i++) {
            ll x = i, f = 0;
            for(j = 1; j < 5; j++) {
                sum += j;
                if(x == n) {
                    f = 1;
                    break;
                }
                x = x * 10 + i;
            }
            if(f) break;
        }
        cout << sum << "\n";
    }
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
