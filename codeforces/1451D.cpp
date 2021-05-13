#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const int mod = 1e9 + 7;
const int N = 103;

int dt(int i, int j) { return (i * i) + (j * j); }

void solve_case() {
    int d, k;
    cin >> d >> k;
    d *= d;
    int mx = 0, rt = sqrt(d) + 1;
    for(int i = 0; i <= rt; i += k) {
        int j = sqrt(d - (i * i));
        j -= (j % k);
        if(dt(i, j) <= d && dt(i + k, j) > d && dt(i, j + k) > d && (i % k == 0) && (j % k == 0))
            mx = max(mx, i/k + j/k);

    }
    cout << (mx % 2 ? "Ashish\n" : "Utkarsh\n");
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
