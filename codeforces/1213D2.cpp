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

const int N = 2e5+2;
int a[N], f[N], g[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,k;
    cin >> n >> k;
    for(i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(i=1; i<=n; i++) {
        g[a[i]]++;
        int cnt = 0;
        while(a[i]) {
            a[i] /= 2;
            cnt++;
            if(g[a[i]] < k) f[a[i]] += cnt, g[a[i]]++;
        }
    }
    int mn = 1e9;
    for(i=0; i<N; i++) {
        if(g[i] < k)
            continue;
        remin(mn, f[i]);
    }
    cout << mn << "\n";
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
