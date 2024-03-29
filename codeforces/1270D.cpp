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
    int n,i,j,k,m=0;
    cin >> n >> k;
    vector<int> a;
    for(i=1; i<=k+1; i++) {
        cout << "? ";
        for(j=1; j<=k+1; j++) {
            if(i!=j) cout << j << " ";
        }
        cout << endl;
        cout.flush();
        int x,y;
        cin >> x >> y;
        a.pb(y);
    }
    sort(all(a), greater<int>());
    int res = a[0];
    for(i=0; i<a.size(); i++) {
        if(a[i]==res) m++;
    }
    cout << "! " << m << endl;
    cout.flush();
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
