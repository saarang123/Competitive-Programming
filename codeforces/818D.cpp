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

const int N = 1e6+2;
int a[N], cnt[N];
set<pair<int, int>> st;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,c1,c2;
    for(i=1; i<=1e6; i++)
        st.insert(mp(0, i));
    cin >> n >> c1;
    for(i=1; i<=n; i++)
        cin >> a[i];
    for(i=1; i<=n; i++) {
        if(st.count(mp(cnt[a[i]], a[i]))) {
            st.erase(mp(cnt[a[i]], a[i]));
            cnt[a[i]]++;
            st.insert(mp(cnt[a[i]], a[i]));
        }
        while(st.begin() -> first < cnt[c1]) {
            st.erase(st.begin());
        }
    }
    if(st.begin() -> second == c1)
        st.erase(st.begin());
    if(st.size())
        cout << st.begin() -> second << "\n";
    else cout << -1 << "\n";
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
