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
int n,a,b,x,y;

int check(int p, int q) {
    int r = a-p;
    r = max(r, x);
    q += (p-(a-r));
    int l = b-q;
    l = max(l, y);
    //cout << r << " " << l << "\n";
    return (r*l);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    cin >> a >> b >> x >> y >> n;
    int ans = 1e18;
    remin(ans, check(0, n));
    remin(ans, check(n, 0));
    remin(ans, check(n/2, n - n/2));
    remin(ans, check(n - n/2, n/2));
    swap(a,b); swap(x,y);
    remin(ans, check(0, n));
    remin(ans, check(n, 0));
    remin(ans, check(n/2, n - n/2));
    remin(ans, check(n - n/2, n/2));
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
