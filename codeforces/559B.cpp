#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, m;
string a, b;

bool solve(int i, int j, int l, int r) {
    if(i > j || l > r) return false;
    if(i == j && l == r) return (a[i] == b[l]);
    bool ok = 1;
    for(int x = 0; x < j - i + 1; x++) {
        ok = ok && (a[i + x] == b[l + x]);
    }
    if(ok)
        return true;
    if((j - i) % 2 && (r - l) % 2) {
        int m1 = (i + j) >> 1, m2 = (l + r) >> 1;
        if(solve(i, m1, l, m2) && solve(m1 + 1, j, m2 + 1, r)) return true;
        if(solve(i, m1, m2 + 1, r) && solve(m1 + 1, j, l, m2)) return true;
    }
    return false;
}

void solve_case() {
    cin >> a >> b;
    n = a.size(), m = b.size();
    if(solve(0, n - 1, 0, n - 1)) cout << "YES\n";
    else cout << "NO\n";
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
