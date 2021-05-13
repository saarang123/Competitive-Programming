#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

set<int> st;

void f(vector<int> &a) {
    if(a.empty()) return;
    int mid = (a[0] + a.back()) / 2, sum = 0;
    vector<int> l, r;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] <= mid) l.pb(a[i]);
        else r.pb(a[i]);
        sum += a[i];
    }
    st.insert(sum);
    if(a[0] == a.back()) return;
    f(l); f(r);
}

void solve_case() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(all(a));
    st.clear();
    f(a);
    while(q--) {
        int x; cin >> x;
        if(st.count(x)) cout << "Yes\n";
        else cout << "No\n";
    }
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
