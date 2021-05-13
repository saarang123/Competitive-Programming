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

#define int long long
int n, m, x, y;
set<array<int, 2>> st;
vector<array<int, 2>> center;

bool qry(int xy, int yx) {
    if(xy > n || yx > n || xy < 1 || yx < 1) return 0;
    cout << "examine " << xy << " " << yx << endl; cout.flush();
    string s; cin >> s;
    return (s == "true" ? 1 : 0);
}

int fst(int a, int b, int dx) {
    int prev = 1, cur = 1 * dx, t = 0;
    while(qry(a + cur, b)) {
        prev = cur;
        cur *= 2;
    }
    t += prev;
    //cout << prev << " " << cur << endl;
    int mn = a + prev, mx = a + cur;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        if(qry(mid, b))
            mn = mid + 1;
        else
            mx = mid;
    }
    //cout << "end of binsearch: " << mn << endl;
    t += abs(a + prev - mn);
    return t;
}


int snd(int a, int b, int dx) {
    int prev = 1, cur = 1 * dx, t = 0;
    while(qry(a, b + cur)) {
        prev = cur;
        cur *= 2;
    }
    t += prev;
    //cout << prev << " " << cur << endl;
    int mn = b + prev, mx = b + cur;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        if(qry(a, mid))
            mn = mid + 1;
        else
            mx = mid;
    }
    //cout << "end of binsearch: " << mn << endl;
    t += abs(b + prev - mn);
    return t;
}

void check(int a, int b) {
    if(st.count({a, b})) return;
    if(!qry(a, b)) return;
    st.insert({a, b});
    center.pb({a, b});
    int dx = 2 * m;
    check(a - dx,  b); check(a + dx, b);
    check(a, b - dx); check(a, b + dx);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    cin >> n >> x >> y;
    array<int, 2> a = {fst(x, y, 1), fst(x, y, -1) };
    array<int, 2> b = {snd(x, y, 1), snd(x, y, -1) };
    array<int, 2> c = { (x + a[0] + x - a[1])/2, (y + b[0] + y - b[1])/2 };
    //for(int o : a) cout << o << " "; cout << endl;
    //for(int o : b) cout << o << " "; cout << endl;
    //for(int o : c) cout << o << " "; cout << endl;
    m = a[0] - 1 + a[1];
    check(c[0], c[1]);
    array<int, 2> ans = {0, 0};
    for(auto ok : center) {
        ans[0] += ok[0]; ans[1] += ok[1];
    }
    //for(auto ok : center) cout << ok[0] << " " << ok[1] << " is a center" << endl;
    ans[0] /= (int) center.size();
    ans[1] /= (int) center.size();
    cout << "solution ";
    cout << ans[0] << " " << ans[1] << endl;
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
