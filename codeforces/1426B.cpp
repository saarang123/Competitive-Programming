#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve_case() {
    int n,i,j,m;
    cin >> n >> m;
    int a[n][2][2];
    for(i = 0; i < n; i++) {
        for(j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++)
                cin >> a[i][j][k];
        }
    }
    if(m % 2)
        return void(cout << "NO" << "\n");
    bool flag = 0;
    for(i = 0; i < n; i++) {
        if(a[i][0][1] == a[i][1][0])
            flag = 1;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
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
