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

const int N = 1e6+2;
int a[N], used[N], b[N];
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    cin >> n;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        b[i] = -1;
    }
    for(i=1; i<=n; i++) {
        if(a[i]!=a[i-1]) {
            b[i] = a[i-1];
            used[b[i]] = 1;
        }
    }
    used[a[n]] = 1;
    j = 0;
    for(i=1; i<=n; i++) {
        if(b[i]!=-1) continue;
        while(used[j]) j++;
        b[i] = j;
        used[j] = 1;
    }
    for(i=1; i<=n; i++) cout << b[i] << " "; cout << "\n";
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
