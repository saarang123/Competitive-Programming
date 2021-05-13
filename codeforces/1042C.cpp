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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<bool> use(n);
    for(int i=0; i<n; i++) cin >> a[i].first, a[i].second = i;
    sort(all(a));
    int neg = 1, cnt=0;
    for(auto v: a) {
        if(v.f < 0) {
            if(neg == 1) neg = -v.ss;
            else {
                cnt = 1;
                use[-neg] = 1;
                use[v.ss] = 1;
                neg = 1;
            }
        }
        else if(v.f > 0) {
            cnt = 1;
            use[v.ss] = 1;
        }
    }
    if(!cnt) use[a.back().ss] = 1;
    int other = -1, last = -1;
    for(int i=0; i<n; i++) {
        if(!use[i]) {
            if(other!=-1)
                cout << 1 << " " << other+1 << " " << i+1 << "\n";
            other = i;
        }
        else {
            if(last!=-1)
                cout << 1 << " " << last+1 << " " << i+1 << "\n";
            last = i;
        }
    }
    if(other!=-1) cout << 2 << " " << other+1 << "\n";
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
