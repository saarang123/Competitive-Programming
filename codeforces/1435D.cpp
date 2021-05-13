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
    int n, i, j;
    cin >> n;
    vector<int> a(2 * n), f(2 * n);
    stack<int> st;
    for(i = 0; i < 2 * n; i++) {
        char c; cin >> c;
        if(c == '+')
            st.push(i);
        else {
            cin >> a[i];
            if(st.empty())
                return void(cout << "NO\n");
            f[st.top()] = a[i];
            st.pop();
        }
    }
    set<int> t;
    for(i = 0; i < 2 * n; i++) {
        if(a[i] == 0)
            t.insert(f[i]);
        else {
            if(*t.begin() != a[i])
                return void(cout << "NO\n");
            t.erase(a[i]);
        }
    }
    cout << "YES\n";
    for(i = 0; i < 2 * n; i++)
        if(!a[i]) cout << f[i] << " "; cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
