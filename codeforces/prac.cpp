#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case(int tc);

const int X = 1000 * 1000 + 3;
int spf[X], dp[X];

void init() {
    spf[1] = 1;
    for (int i=2; i<X; i++)
        spf[i] = i;
    for (int i=4; i<X; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<X; i++) {
        if (spf[i] == i) {
            for (int j=i*i; j<X; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<int> fct(int x) {
    vector<int> kek;
    while(x != 1) {
        kek.push_back(spf[x]);
        x /= spf[x];
    }
    sort(kek.begin(), kek.end());
    kek.resize(unique(kek.begin(), kek.end()) - kek.begin());
    return kek;
}

void fill() {
    dp[1] = dp[2] = -X;
    dp[3] = dp[4] = dp[5] = 1;
    for(int i = 6; i < 50; i++) {
        vector<int> kek = fct(i);
        dp[i] = 1;
        for(int x : kek) if(x != i)
            dp[i] = max(dp[i], 1 + dp[x]);
    }
}

map<array<int, 2>, int> cnt;

int f(int sum, int p) {
    //cout << sum << ' ' << p << endl;
    if(sum == 0) return 0;
    if(sum < 3)
        return -X;
    if(cnt.count({sum, p})) return cnt[{sum, p}];
    array<int, 2> best = {1, sum};
    if(p < 0) {
        for(int i = 3; i <= sum; i++)
            best = max(best, {1 + f(sum - i, i), i});
    } else {
        vector<int> kek = fct(p);
        for(int x : kek) if(x != p)
            best = max(best, {1 + f(sum - x, x), x});
    }
    return cnt[{sum, p}] = best[0];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1, i = 1;
    init();
    memset(dp, -1, sizeof dp);
    //fill();
    std::cin >> tt;
    while(tt--) {
        solve_case(i++);
    }
    return 0;
}

void solve_case(int tc) {
    cout << "Case " << "#" << tc << ": ";
    int n; cin >> n;
    cout << f(n, -1) << '\n';
}
