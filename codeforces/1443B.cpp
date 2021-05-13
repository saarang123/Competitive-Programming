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
    int a, b, i, j, n;
    cin >> a >> b;
    string s; cin >> s;
    n = s.size();
    vector<array<int, 2>> c;
    c.pb({0, 0});
    int cnt = 0;
    for(i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        j = i;
        while(j < n && s[j] == s[i]) j++;
        cnt++;
        c.pb({i + 1, j});
        i = j;
    }
    int ans = a * cnt;
    //cout << "first: "  << ans << "\n";
    int prev = 0, t = 0;
    for(i = 1; i < c.size(); i++) {
        t++;
        //cout << prev << ' ' << c[i][0] << ' ' << c[i - 1][1] << ' ' << t << '\n';
        int tmp = min(prev + a, prev + (c[i][0] - c[i - 1][1] - 1) * b);
        if(c[i - 1][1] == 0) tmp = a;
        prev = tmp;
        tmp += (cnt - t) * a;
        ans = min(ans, tmp);
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
