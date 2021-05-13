#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element, element -= 1; return is; }

void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    cin >> a; cin >> b; cin >> c;
    vector<int> on[n], p[n], ans(m, -1), off[n];
    for(int i = 0; i < m; i++)
        p[c[i]].push_back(i);
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            on[b[i]].push_back(i);
        else 
            off[b[i]].push_back(i);
    multiset<int> unfixed;
    for(int i = 0; i < n; i++) {
        if(on[i].size() > p[i].size()) return void(cout << "NO\n");
        int j = 0;
        if(on[i].empty() && off[i].empty()) continue;
        if(on[i].empty()) {
            for(int x : p[i]) {
                ans[x] = off[i][0];
                unfixed.insert(ans[x]);
            }
            continue;
        }
        for(int x : p[i]) {
            if(j >= on[i].size()) ans[x] = on[i].back();
            else ans[x] = on[i][j++];
            unfixed.insert(ans[x]);
        }
    }
    for(int i = 0; i < m; i++) {
        if(ans[i] != -1) {
            a[ans[i]] = c[i];
            unfixed.erase(unfixed.find(ans[i]));
        } else {
            if(unfixed.empty()) return void(cout << "NO\n");
            int x = *unfixed.begin();
            ans[i] = x;
        }
    }
    cout << "YES" << '\n';
    for(int x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
}