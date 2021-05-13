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
    int n,i,j;
    cin >> n;
    int a[n+2], b[n+2];
    for(i=1; i<=n; i++) {
        cin >> a[i], b[i] = a[i];
    }
    sort(b+1, b+n+1);
    int mx = b[1];
    for(i=1; i<=n; i++) {
        if(a[i]==b[i]) continue;
        if(__gcd(a[i], mx) != mx) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
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
