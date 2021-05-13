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

const int N = 1e5 + 2;
const int inf = 1e9;
int a[N];
int n;
int qry(int i) {
    if(a[i] != 0) return a[i];
    else {
        cout << "? " << i << '\n';
        cout.flush();
        int k; cin >> k;
        return a[i] = k;
    }
}

bool check(int k) {
    if(k < 1 || k > n) return false;
    int a = qry(k - 1), b = qry(k), c = qry(k + 1);
    if(b < a && b < c) {
        cout << "! " << k << '\n';
        cout.flush();
        exit(0);
    }
    if(a < b && b < c) return true;
    return false;
}

void solve_case() {
    cin >> n;
    a[0] = a[n + 1] = inf;
    int mn = 1, mx = n;
    while(mn <= mx) {
        int mid = (mn + mx) >> 1;
        if(check(mid)) {
            mx = mid - 1;
        } else {
            mn = mid + 1;
        }
    }
    check(mn); check(mx);
    cout << "! 1" << '\n';
    cout.flush();
}
