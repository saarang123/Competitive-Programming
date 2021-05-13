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
    map<int, int> cnt;
    vector<int> gcd(n*n), a;
    for(i=0; i < n*n; i++) {
        cin >> gcd[i];
    }
    sort(all(gcd), greater<int>());
    for(int u: gcd) cnt[u]++;
    while(!cnt.empty() && a.size() < n) {
        auto x = *cnt.rbegin();
        if(x.second == 1) {
            cnt.erase(x.first);
        }
        else {
            cnt[x.first] -= 1;
        }
        for(int u: a) {
            int g = __gcd(u, x.first);
            if(cnt[g] == 2) {
                cnt.erase(g);
            }
            else {
                cnt[g] -= 2;
            }
        }
        a.pb(x.first);
    }
    for(int u: a) cout << u << " "; cout << "\n";
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
