#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    cin >> n;
    int a[n];
    for(i=0; i<n; i++) {
        char c;
        cin >> c;
        a[i] = c-'0';
    }
    int ans = 0;
    for(i=0; i<n-1; i++) {
        if(a[i]==a[i+1]) {
            ans++;
            a[i+1] ^= 1;
        }
    }
    cout << min(ans, n-ans) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
