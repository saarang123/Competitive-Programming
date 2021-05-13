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
    bool b[] = {0, 0};
    vector<int> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > 0) b[0] = 1;
        if(a[i] < 0) b[1] = 1;
    }
    if(n == 1) {
        return void(cout << a[0] << "\n");
    }
    sort(all(a));
    //cout << b[0] << b[1] << "\n";
    if(b[0] && b[1]) {
        int ans = 0;
        for(int x: a) ans += abs(x);
        cout << ans << "\n";
    }
    else if(b[0]) {
        int ans = -a[0];
        for(i = 1; i < n; i++) ans += a[i];
        cout << ans << "\n";
    }
    else {
        int ans = a.back();
        for(i = 0; i < n - 1; i++) ans += -a[i];
        cout << ans << "\n";
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
