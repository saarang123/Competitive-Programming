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

const int N = 103;
bool dp[2*N][N][53][2];
string s;
int ans = 0, n, m;

void f(int x, int i, int j, int dx) {
    if(dp[x+100][i][j][dx])
        return;
    dp[x+100][i][j][dx] = 1;
    if(i == n+1) {
        if(j == 0)
            remax(ans, abs(x));
        return;
    }
    for(int k=0; k<=j; k++) {  //no. of moves done on index i
        int v = (s[i] == 'F');
        if(k % 2) v ^= 1;
        int y = (dx == 0 ? -1:1);
        int dy = (v == 0 ? dx ^ 1 : dx);
        f(x + v*y, i+1, j-k, dy);
    }
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j; //saw solution :((
    cin >> s >> m;
    n = s.size();
    s = " " + s;
    f(0, 1, m, 1);
    cout << ans << "\n";
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
