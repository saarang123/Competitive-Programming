#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


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
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, k;
    cin >> n >> k;
    vector<char> s[k];
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            s[i].push_back('a' + j);
    string ans = "a";
    while(ans.size() < n) {
        int id = ans.back() - 'a';
        if(s[id].empty()) {
            for(int i = 0; i < k; i++)
                s[id].push_back('a' + i);
        }
        ans += s[id].back();
        s[id].pop_back();
    }
    cout << ans << '\n';
}