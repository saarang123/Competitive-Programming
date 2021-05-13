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
const int N = 1e5+2;
int a[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> a[i];
    if(n==1) {
        cout << 1 << " " << 1 << "\n";
        cout << -a[1] << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 0 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 0 << "\n";
        return;
    }
    cout << 1 << " " << n-1 << "\n";
    vector<int> tmp;
    for(i=1; i<n; i++) {
        if(a[i] % n==0) {
            tmp.pb(0);
            continue;
        }
        int y = a[i] % n;
        tmp.pb(y * (n-1));
        a[i] += (y * (n-1));
    }
    for(int u: tmp) cout << u << " "; cout << "\n";
    cout << n << " " << n << "\n";
    cout << -a[n] << "\n";
    a[n] = 0;
    cout << 1 << " " << n << "\n";
    for(i=1; i<=n; i++) {
        cout << -a[i] << " ";
    }
    cout << "\n";
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
