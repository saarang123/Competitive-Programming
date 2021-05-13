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

const int N = 1e5+3;
map<int, int> cnt;
int f[N], a[N];

bool is(pair<int, int> x, pair<int, int> y) {
    if(x.second == 1 && (x.first-1 == y.first || x.first-1 == 0))
        return true;
    return false;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> a[i];
    int mx = -1;
    set<int> st;
    for(i=1; i<=n; i++) st.insert(a[i]);
    if(st.size() == 1)
        return void(cout << n << "\n");
    vector<pair<int, int>> tmp;
    for(i=1; i<=n; i++) {
        tmp.clear();
        if(cnt.count(f[a[i]])) cnt[f[a[i]]]--;
        if(cnt[f[a[i]]]==0) cnt.erase(f[a[i]]);
        f[a[i]]++;
        cnt[f[a[i]]]++;
        /*cout << "FREQ: \n";
        for(j=1; j<=n; j++) cout << f[j] << " \n"[j==n];
        cout << "MAP: \n";
        for(auto p: cnt) {
            cout << p.first << ": " << p.second << "\n";
        }cout << "----------\n";*/
        if(cnt.size() > 2) continue;
        for(auto p: cnt) tmp.pb(p);
        if(tmp.size()==1) {
            if(tmp[0].first == 1)
                mx = i;
            continue;
        }
        if(is(tmp[0], tmp[1]) || is(tmp[1], tmp[0]))
            mx = i;
    }
    cout << mx << "\n";
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
