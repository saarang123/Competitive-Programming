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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    int bit = 30;
    cin >> n;
    vector<int> a(n);
    for(i = 0; i < n; i++) cin >> a[i];
    while(bit >= 0) {
        int c = 0;
        for(i = 0; i < n; i++) if(a[i] & (1 << bit)) c++;
        //cout << bit << " " << c << " cnt\n";
        if(c % 2) break;
        bit--;
    }
    if(bit < 0)
        return void(cout << "DRAW\n");
    int cnt[] = {0, 0};
    for(i = 0; i < n; i++) {
        if(a[i] & (1 << bit)) cnt[0]++;
        else cnt[1]++;
    }
    if(cnt[1] % 2 == 0 && cnt[0] % 4 == 3) cout << "LOSE\n";
    else cout << "WIN\n";
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
