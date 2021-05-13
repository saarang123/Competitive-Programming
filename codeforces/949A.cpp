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

const int N = 2e5+2;
vector<vector<int>> ans;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    set<int> ok[2];
    for(i=1; i<=n; i++)
        ok[s[i]-'0'].insert(i);
    while(!ok[0].empty()) {
        i = *ok[0].begin();
        ok[0].erase(i);
        vector<int> tmp;
        tmp.pb(i);
        //cout << i << ": ";
        while(1) {
            auto it = ok[1].lower_bound(i);
            if(it == ok[1].end()) break;
            int fst = *it;
            it = ok[0].lower_bound(fst);
            if(it == ok[0].end()) break;
            int snd = *it;
            tmp.pb(fst);
            tmp.pb(snd);
            ok[1].erase(fst); ok[0].erase(snd);
            i = snd;
            //cout << fst << " " << snd << " ";
        }
        //cout << "\n";
        ans.pb(tmp);
    }
    if(ok[1].size()) {
        return void(cout << -1 << "\n");
    }
    cout << ans.size() << "\n";
    for(auto v: ans) {
        cout << v.size() << " ";
        for(int u: v) cout << u << " "; cout << "\n";
    }
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
