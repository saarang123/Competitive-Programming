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
    int n; cin >> n;
    vector<string> a(n);
    for(auto &x : a) cin >> x;
    for(int r1 = 0; r1 < 3; r1++) {
        int tot = 0, used = 0;
        vector<string> b(n);
        for(int r2 = 0; r2 < 3; r2++) {
            tot = 0, used = 0;
            for(int i = 0; i < n; i++) {
                string c = "";
                for(int j = 0; j < n; j++) {
                    if(a[i][j] == '.') {c += "."; continue; }
                    tot++;
                    if(i % 3 == r1 && j % 3 == r2) c += "O";
                    else if(i % 3 == (r1 + 1) % 3 && j % 3 == (r2 + 1) % 3) c += "O";
                    else if(i % 3 == (r1 + 2) % 3 && j % 3 == (r2 + 2) % 3) c += "O";
                    else {c += "X"; used++; }
                }
                b[i] = c;
            }
            used = tot - used;
            if(used <= tot / 3) break;
        }
        if(used <= tot / 3) {
            swap(a, b);
            break;
        }
    }
    for(auto x : a) cout << x << '\n';
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
