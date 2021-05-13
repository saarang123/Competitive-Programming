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

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());z
#define int long long

const int N = 4e5+2;
const int inf = 1e17;
int up[N][20], sum[N][20], w[N], n = 1, last = 0;
void solve_case() {
    // :pray: :fishy: :orz:print(*[(str(chr(ord('A')-1+c))+" ")*c for c in range(1,4)])
    int tp, wt, i, j, x, a;
    cin >> tp;
    if(tp==1) {
        cin >> a >> wt;
        a ^= last;
        wt ^= last;
        n++;
        w[n] = wt;
        int to = a;
        for(i=19; i>=0; i--) {
            if(w[up[to][i]]<w[n]) {
                to = up[to][i];
            }
        }
        up[n][0] = up[to][0];
        if(w[a]>=w[n]) up[n][0] = a;
        sum[n][0] = w[up[n][0]];
        for(i=1; i<20; i++) {
            up[n][i] = up[up[n][i-1]][i-1];
            sum[n][i] = sum[n][i-1] + sum[up[n][i-1]][i-1];
        }
        //cout << "sums: " << endl;
        //for(i=1; i<=n; i++) { cout << i << ": " << endl; for(j=0; j<20; j++) cout << sum[i][j] << " "; cout << endl; }
        //cout << "parents: " << endl;
        //for(i=1; i<=n; i++) { cout << i << ": " << endl; for(j=0; j<20; j++) cout << up[i][j] << " "; cout << endl; }
    }
    else {
        cin >> a >> x;
        a ^= last;
        x ^= last;
        //cout << a << " " << x << " " << w[a] << " query\n";
        if(w[a]>x) {
            cout << 0 << "\n";
            last = 0;
            return;
        }
        int ans = 1;
        x -= w[a];
        for(i=19; i>=0; i--) {
            if(sum[a][i] <= x) {
                ans += (1<<i);
                x -= sum[a][i];
                a = up[a][i];
            }
        }
        cout << ans << "\n";
        last = ans;
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    w[0] = inf;
    for(int j=0; j<20; j++) sum[1][j] = inf;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
