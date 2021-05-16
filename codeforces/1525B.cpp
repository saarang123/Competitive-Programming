#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
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
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    vector<int> o(n);
    iota(o.begin(), o.end(), 1);
    if(a == o)
        return cout << 0 << '\n', void();
    if(a[0] == 1 || a.back() == n)
        cout << 1 << '\n';
    else {
        if(a[0] == n && a.back() == 1)
            cout << 3 << '\n';
        else
            cout << 2 << '\n';
    }
}
