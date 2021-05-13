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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    set<int> st;
    vector<int> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    if(st.size() == 1)
        return void(cout << -1 << "\n");
    vector<int> b = a;
    sort(all(b));
    int x = b.back();
    for(i = 0; i < n; i++) {
        if(a[i] != x) continue;
        if(i && a[i - 1] != x)
            return void(cout << i + 1 << "\n");
        if(i < n - 1 && a[i + 1] != x)
            return void(cout << i + 1 << "\n");
    }
    cout << -1 << "\n";
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
