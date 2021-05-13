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

const int N = 1e5+2;
vector<int> g[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,d,h,x,y;
    cin >> n >> x >> y;
    d = x; h = y;
    if(d==h && d==1 && n>2)
        return void(cout << -1 << "\n");
    if(d > 2*h) {
        return void(cout << -1 << "\n");
    }
    i = 1, j = 2;
    d -= h;
    while(h--) {
        cout << i << " " << j << "\n";
        i = j; j++;
    }
    i = 1;
    while(d--) {
        cout << i << " " << j << "\n";
        i = j; j++;
    }
    while(j<=n) {
        cout << ((x == y) ? 2 : 1) << " " << j++ << "\n";
    }
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
