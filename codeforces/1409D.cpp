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
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,sum, in;
    string s;
    cin >> s >> sum;
    stringstream st(s);
    st >> in;
    n = 0;
    for(char c: s) n += (c-'0');
    if(n <= sum) {
        cout << 0 << "\n";
        return;
    }
    reverse(all(s));
    s += "0";
    i = 0;
    int sz = s.size();
    while(n >= sum && i < sz) {
        n -= (s[i]-'0');
        s[i] = '0';
        i++;
    }
    while(i < sz && s[i] == '9') {
        s[i] = '0';
        i++;
    }
    s[i]++;
    reverse(all(s));
    stringstream st1(s);
    int num;
    st1 >> num;
    //cout << s << " " << num << "\n";
    cout << num-in << "\n";
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
