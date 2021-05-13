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

int gcd1(int a, int b)
{
    if (a == 0)
        return b;
    return gcd1(b % a, a);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    vector<int> a(n), b;
    vector<bool> used(n, false);
    for(i=0; i<n; i++) cin >> a[i];
    int gcd = 0;
    for(i=0; i<n; i++) {
        int mx = -1, tmp = 0;
        for(j=0; j<n; j++) {
            if(used[j])
                continue;
            if(remax(tmp, gcd1(gcd, a[j])))
                mx = j;
        }
        used[mx] = 1;
        b.pb(a[mx]);
        gcd = gcd1(gcd, b.back());

    }
    for(int u: b) cout << u << " "; cout << "\n";
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
