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

const int N = 5003;
int a[N];

int f(int l, int r, int x) {
    int ans = 0;
    int mn = 2e9;
    int i,j;
    for(i=l; i<=r; i++) remin(mn, a[i]);
    ans += mn-x;
    for(i=l, j=l; i<=r; i=j) {
        if(a[i] == mn) {x
            j++;
            continue;
        }
        while(j<=r && a[j]!=mn) j++;
        ans += f(i, j-1, mn);
    }
    remin(ans, r-l+1);
    return ans;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i=1; i<=n; i++) cin >> a[i];
    cout << f(1, n, 0) << "\n";
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
