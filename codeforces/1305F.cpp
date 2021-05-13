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
    int n,i,j;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = n + 5;
    for(int _ = 0; _ < 7; _++) {
        int id = rng() % n;
        for(int i = -1; i <= 1; i++) {
            int x = a[id] + i;
            if(x < 1) continue;
            vector<int> primes;
            for(int j = 2; j * j <= x; j++) {
                if(x % j) continue;
                primes.pb(j);
                while(x % j == 0) x /= j;
            }
            if(x > 1) primes.pb(x);
            int c = abs(i);
            a[id] += i;
            for(int k : primes) {
                int tmp = c;
                for(int el : a) {
                    if(el >= k) tmp += min(el % k, k - (el % k));
                    else tmp += k - (el % k);
                }
                //cout << id << ' ' << i << ' ' << k << ' ' << tmp << '\n';
                ans = min(ans, tmp);
            }
            a[id] -= i;
        }
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
