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
    char f[n + 2][n + 2];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cin >> f[i][j];
    char a = f[0][1], b = f[1][0], c = f[n - 1][n - 2], d = f[n - 2][n - 1];
    if(a == b && b == c && c == d) {
        cout << 2 << "\n";
        cout << 2 << " " << 1 << "\n";
        cout << 1 << " " << 2 << "\n";
        return;
    }
    if(a == b && c == d && b != c) {
        cout << 0 << "\n";
        return;
    }
    if(a == b && c != d) {
        cout << 1 << "\n";
        if(a == c) cout << n << " " << n - 1 << "\n";
        else cout << n - 1 << " " << n << "\n";
        return;
    }
    if(c == d && a != b) {
        cout << 1 << "\n";
        if(a == c) cout << 1 << " " << 2 << "\n";
        else cout << 2 << " " << 1 << "\n";
        return;
    }
    if(a != b && c != d) {
        cout << 2 << "\n";
        if(a == c) {
            cout << 2 << " " << 1 << "\n";
            cout << n << " " << n - 1 << "\n";
        }
        else {
            cout << 2 << " " << 1 << "\n";
            cout << n - 1 << " " << n << "\n";
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
