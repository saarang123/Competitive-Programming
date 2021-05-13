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
    int n,k,i,j;
    cin >> n;
    int a[] = {6,10,14,15};
    for(i=0; i<4; i++) {
        for(j=i+1; j<4; j++) {
            for(k=j+1; k<4; k++) {
                int left = n - a[i] - a[j] - a[k];
                if(left==a[i] || left==a[j] || left==a[k] || left<=0) continue;
                cout << "YES\n";
                cout << a[i] << " " << a[j] << " " << a[k] << " " << left << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
