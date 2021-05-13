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

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    string s;
    vector<int> weights;
    cin >> s >> n;
    for(i=0; i<10; i++) if(s[i]=='1') weights.pb(i+1);
    vector<int> ans;
    function<void(int, int, int)> dfs = [&] (int cur, int prev, int left) {
        if(left == 0) {
            cout << "YES\n";
            for(int e: ans) cout << e << " "; cout << "\n";
            exit(0);
        }
        for(int w: weights) {
            if(w==prev || w<=cur) continue;
            ans.pb(w);
            dfs(w-cur, w, left-1);
            ans.pop_back();
        }
    };
    dfs(0, 0, n);
    cout << "NO\n";
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
