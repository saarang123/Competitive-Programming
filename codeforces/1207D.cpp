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

#define int long long
const int N = 3e5+2;
const int mod = 998244353;
int f[N];

void init(int n) {
    f[0] = 1;
    for(int i = 1; i <= n; i++)
        f[i] = (f[i - 1] * i) % mod;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    init(n);
    vector<pair<int, int>> v(n);
    map<int, int> a, b;
    map<pair<int, int>, int> bt;
    for(i = 0; i < n; i++) {
        int t, u;
        cin >> t >> u;
        a[t]++; b[u]++;
        v[i] = mp(t, u);
        bt[v[i]]++;
    }
    int ans = f[n];
    int c = 1;
    for(auto x: a)
        c *= f[x.second], c %= mod;
    ans = (ans - c + mod) % mod;
    c = 1;
    for(auto x: b)
        c *= f[x.second], c %= mod;
    ans = (ans - c + mod) % mod;
    sort(all(v));
    int flag = 1;
    for(auto x: bt)
        flag *= f[x.second], flag %= mod;
    for(i = 1; i < n; i++) {
        if(v[i].second < v[i - 1].second)
            flag = 0;
    }
    ans = (ans + flag) % mod;
    cout << ans << "\n";
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
