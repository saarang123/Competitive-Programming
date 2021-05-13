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

int n, x, ans = 0;

int fix(vector<int> &a) {
    for(int i = 1; i < n; i++) {
        if(a[i - 1] <= a[i]) continue;
        int k = -1;
        for(int j = i; j >= 0; j--) {
            if(x < a[j]) k = j;
        }
        if(k == -1) {
            return 1;
        }
        ans++;
        swap(a[k], x);
        return 0;
    }
}

void solve_case() {
    cin >> n >> x;
    vector<int> a(n);
    for(int &c : a) cin >> c;
    ans = 0;
    while(1) {
        bool ok = 1;
        for(int i = 1; i < n; i++) ok = ok && (a[i - 1] <= a[i]);
        if(ok) break;
        if(fix(a)) {
            ans = -1;
            break;
        }

    }
    cout << ans << '\n';
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
