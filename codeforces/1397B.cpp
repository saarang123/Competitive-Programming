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
int a[N], n;

int f(int x) {
    int ans = 1;
    for(int i=2; i<=1e6; i++) {
        int c = 1, cnt = 1;
        while(c <= x) {
            c *= i;
            cnt++;
        }
        if(cnt >= n)
            ans = i;
    }
    return ans;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    cin >> n;
    for(i=0; i<n; i++) cin >> a[i];
    if(n==1) {
        cout << abs(a[0]-1) << "\n";
        return;
    }
    sort(a, a+n);
    int m = f(1e10);
    int cost = 2e18;
    for(i=1; i<=m; i++) {
        int c = 1, tmp = 0;
        //cout << "power is: " << i << "\n";
        for(j=0; j<n; j++) {
            //cout << c << " ";
            tmp += abs(a[j]-c);
            c *= i;
        }
        //cout << "\n";
        remin(cost, tmp);
    }
    cout << cost << "\n";
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
