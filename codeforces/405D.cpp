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
const int N = 1e6+2;
const int S = 1e6;
int a[N], f[N], sum = 0, need = 0;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    vector<int> b;
    int c = 0;
    for(i=1; i<=n; i++) {
        if(f[S+1-a[i]]) {
            c++;
            continue;
        }
        b.pb(S+1-a[i]);
        f[S+1-a[i]]++;
    }
    c /= 2;
    for(i=1; i<N-1; i++) {
        if(c == 0)
            break;
        if(f[i] || f[S+1-i])
            continue;
        c--;
        f[i]++;
        f[S+1-i]++;
        b.pb(i);
        b.pb(S+1-i);
    }
    cout << b.size() << "\n";
    for(int u: b) cout << u << " "; cout << "\n";
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
