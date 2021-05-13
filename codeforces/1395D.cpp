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
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,m,k;
    cin >> n >> k >> m;
    vector<int> above, below;
    for(i=0; i<n; i++) {
        cin >> j;
        if(j>m) above.pb(j);
        else below.pb(j);
    }
    sort(all(above), greater<int>());
    sort(all(below), greater<int>());
    int na = below.size();
    vector<int> pref(na+2,0);
    for(i=1; i<=na; i++)
        pref[i] = pref[i-1] + below[i-1];
    int ans = 0, mx = 0;
    for(i=0; i<=above.size(); i++) {
        if(i) mx += above[i-1];
        int nxt = n - (k+1)*i + k;
        if(nxt<0) continue;
        remin(nxt, na);
        remax(ans, mx + pref[nxt]);
    }
    cout << ans << "\n";
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
