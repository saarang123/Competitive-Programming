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
const int N = 203;
int dp[N][N][N],n,m;
string s,t;
//dp[i][j][k] - cnt of subsequences in prefix i with j moves and k occurences of t[0]

int f(int i, int j, int k) {
    if(j > m) {
        return -1e17;
    }
    if(i == n+1)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    int res = f(i+1, j, k);
    remax(res, f(i+1, j+1, k));
    remax(res, f(i+1, j + (s[i] != t[0]), k+1));
    remax(res, k + f(i+1, j + (s[i] != t[1]), k));
    return dp[i][j][k] = res;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j,k;
    cin >> n >> m;
    cin >> s >> t;
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            for(k=0; k<=n; k++)
                dp[i][j][k] = -1;
    s = " " + s;
    if(t[0] == t[1]) {
        int cnt = 0;
        for(char c: s)
            cnt += (c == t[0]);
        cnt += m;
        remin(cnt, n);
        cout << (cnt*(cnt-1)/2) << "\n";
        return;
    }
    cout << f(1,0,0) << "\n";
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
