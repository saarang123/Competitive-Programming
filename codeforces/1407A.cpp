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
    int n,i,j;
    cin >> n;
    vector<int> a(n);
    for(i=0; i<n; i++) cin >> a[i];
    int c = 0;
    for(i=0; i<n; i++) c += (a[i] == 1);
    if(c <= n/2) {
        cout << n-c << "\n";
        for(i=0; i<n-c; i++) cout << 0 << " "; cout << "\n";
    }
    else {
        if(c % 2 == 0) {
            cout << c << "\n";
            for(i=0; i<c; i++) cout << 1 << " "; cout << '\n';
        }
        else {
            cout << c-1 << "\n";
            for(i=0; i<c-1; i++) cout << 1 << " "; cout << "\n";
        }
    }
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
