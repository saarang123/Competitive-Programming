#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mxn = 1002;
vector<vector<int>> a;
int n, k;

int query(int l, int r, int ignore = -1) {
    vector<int> q;
    for(int i = l; i <= r; i++) if(i != ignore) {
        for(int x : a[i])
            q.push_back(x);
    }
    cout << "? " << q.size() << ' ';
    for(int x : q)
        cout << x << ' ';
    cout << endl;
    int res; cin >> res;
    if(res < 0)
        assert(false);
    return res;
}

void solve() {
    cin >> n >> k;
    a.resize(k + 1);
    for(int i = 1; i <= k; i++) {
        int c; cin >> c;
        while(c--) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    cout << "? " << n << ' ';
    for(int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << endl;
    int cmax; cin >> cmax;
    int mn = 1, mx = k;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        int x = query(mn, mid);
        if(x == cmax)
            mx = mid;
        else
            mn = mid + 1;
    }
    set<int> s;
    for(int i = 1; i <= n; i++) 
        s.insert(i);
    for(int x : a[mn])
        s.erase(x);
    cout << "? " << s.size() << ' ';
    for(int x : s)
        cout << x << ' ';
    cout << endl;
    int second; cin >> second;
    cout << "! ";
    for(int i = 1; i <= k; i++) {
        if(i == mn)
            cout << second << ' ';
        else
            cout << cmax << ' ';
    }
    cout << endl;
    a.clear();
    string ans; cin >> ans;
    assert(ans == "Correct");
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tc; cin >> tc;
    while(tc--)
        solve();
    return 0;
}