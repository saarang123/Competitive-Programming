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

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    vector<int> a;
    for(i=1; i<=n; i++ ){
        j = i;
        if(s[i]!='1') continue;
        while(j<=n && s[j]==s[i]) j++;
        a.pb(j-i);
        i = j;
    }
    sort(all(a), greater<int>());
    //for(int u: a) cout << u << " "; cout << "\n";
    int x = 0;
    for(i=0; i<a.size(); i++) {
        if(i%2==0) x += a[i];
    }
    cout << x << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
