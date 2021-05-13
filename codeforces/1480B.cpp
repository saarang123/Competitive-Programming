#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int A, B, n;
    cin >> A >> B >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i][0];
    for(int i = 0; i < n; i++) 
        cin >> a[i][1];
    sort(all(a), greater<>());
    int sum = 0;
    for(int i = 1; i < n; i++)
        sum += a[i][0] * ((a[i][1] + A - 1) / A);
    int c = (a[0][1] + A - 1) / A;
    if(B - (sum + (c - 1) * a[0][0]) <= 0) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}