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
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> neg, pos;
    for(int &x : a) {
        cin >> x;
        if(x <= 0)
            neg.push_back(x);
        else
            pos.push_back(x);
    }
    sort(all(neg));
    sort(all(pos));
    int ans = neg.size(), mndiff = 2e9 + 3;
    for(int i = 1; i < neg.size(); i++) {
        mndiff = min(mndiff, abs(neg[i] - neg[i - 1]));
    }
    if(!pos.empty() && pos[0] <= mndiff)
        ans++;
    cout << ans << '\n';
}
