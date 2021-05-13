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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int sm = 0;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
        s.insert(a[i]);
    }
    if(sm == x)
        return void(cout << "NO" << '\n');
    vector<int> c;
    int sum = 0;
    while(c.size() < n) {
        auto it = s.begin();
        while(it != s.end() && sum + *it == x)
            it++;
        c.push_back(*it);
        sum += *it;
        s.erase(it);
    }
    cout << "YES" << '\n';
    for(int y : c)
        cout << y << ' ';
    cout << '\n';
}
