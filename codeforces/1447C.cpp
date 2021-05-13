#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case() {
    int n, w;
    cin >> n >> w;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i][0], a[i][1] = i;
    int half = (w + 1)/2;
    sort(all(a));
    if(a[0][0] > w)
        return void(cout << -1 << '\n');
    reverse(all(a));
    vector<int> id;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + a[i][0] > w) continue;
        sum += a[i][0];
        id.pb(a[i][1]);
        if(sum >= half) {
            cout << id.size() << '\n';
            for(int x : id) cout << x + 1 << ' '; cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
