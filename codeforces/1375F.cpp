#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long

int ask(int x) {
    cout << x << endl;
    cout.flush();
    int q; cin >> q; --q;
    return q;
}

void solve_case() {
    // :pray: :fishy: :orz:
    vector<int> a(3), b(3);
    cin >> a[0] >> a[1] >> a[2];
    cout << "First" << endl;
    cout.flush();
    a[ask(2e9)] += 2e9;
    b = a;
    sort(all(b));
    int r = ask(2*b[2]-b[1]-b[0]);
    a[r] += 2*b[2]-b[1]-b[0];
    ask(a[1]-a[0]);
    sort(all(a));
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
