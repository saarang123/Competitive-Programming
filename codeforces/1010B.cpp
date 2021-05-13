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

int a[32];

int qry(int x) {
    cout << x << "\n"; cout.flush();
    int tp; cin >> tp;
    if(tp == 0) exit(0);
    return tp;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,m,i,j;
    cin >> m >> n;
    for(i = 0; i < n; i++) {
        int x = qry(m);
        if(x == -1) a[i] = 1;
        else a[i] = -1;
    }
    int cnt = 0, mn = 1, mx = m;
    while(mn <= mx) {
        int mid = (mn + mx) >> 1;
        int x = qry(mid) * a[cnt++];
        if(x == -1) mx = mid - 1;
        else mn = mid + 1;
        cnt %= n;
    }
    cout << mn << "\n"; cout.flush();
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
