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
    int a[n], l = -1, r = 2e9;
    for(i=0; i<n; i++) cin >> a[i], remax(l, a[i]);

    function<bool(int x)> check = [&] (int x) {
        int cnt = 0;
        for(i=0; i<n; i++) cnt += (x - a[i]);

        int good = 1;
        for(i=0; i<n; i++) {
            good = good && (cnt - (x-a[i]) >= a[i]);
        }
        return good;
    };
    while(l!=r) {
        int mid = (l+r) >> 1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << "\n";
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
