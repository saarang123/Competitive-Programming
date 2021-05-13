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

const int N = 3e5+2;
string s;
int f[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,k,j;
    cin >> n >> k;
    cin >> s;
    for(i=0; i<n; i++) f[i] = -1;
    for(i=0; i<n; i++) {
        int x = -1;
        if(s[i] == '1') x = 1;
        else if(s[i] == '0') x = 0;
        if(x == -1)
            continue;
        if(f[i % k] == -1) {
            f[i % k] = x;
        }
        else if(f[i % k] != x) {
            cout << "NO" << "\n";
            return;
        }
    }
    int c1 = 0, c2 = 0;
    for(i=0; i<k; i++) {
        c1 += (f[i] == 0);
        c2 += (f[i] == 1);
    }
    if(c1 > k/2 || c2 > k/2) cout << "NO" << "\n";
    else cout << "YES" << "\n";
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
