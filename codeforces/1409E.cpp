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
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(i=0; i<n; i++)  cin >> a[i];
    for(i=0; i<n; i++)  cin >> b[i];
    sort(all(a));
    //for(int u: a) cout << u << " "; cout << "\n";
    vector<pair<int, int>> q;
    for(i=0; i<n; i++) {
        j = upper_bound(all(a), a[i]+k) - a.begin();
        int cnt = j-i;
        q.pb(mp(a[i], cnt));
        //cout << a[i] << " " << cnt << "\n";
    }
    sort(all(q));/*
    cout << "QUERIES: ";
    for(auto p: q) cout << p.first << " " << p.second << "\n";
    cout << "------------\n";*/
    int mx[n+1];
    mx[n] = 0;
    for(i=n-1; i>=0; i--)
        mx[i] = max(q[i].second, mx[i+1]);
    function<int(int l, int r)> sum = [&] (int l, int r) {
        if(l > r)
            return 0;
        return mx[l];
    };
    int ans = 0;
    for(i=0; i<n; i++) {
        int tmp = q[i].second;
        int nxt = q[i].first + k + 1;
        j = lower_bound(all(q), mp(nxt, -1)) - q.begin();
        tmp += max(0, sum(j,n-1));
        remax(ans, tmp);
        //cout << tmp << " " << j << "\n";
    }
    //cout << "\n";
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
