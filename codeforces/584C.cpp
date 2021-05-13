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
    int n,i,j,t;
    cin >> n >> t;
    t = n - t;
    string s1,s2,s3 = "";
    cin >> s1 >> s2;
    for(i=0; i<n; i++) s3 += " ";
    int c = 0;
    for(i=0; i<n; i++) {
        if(s1[i] == s2[i] && c<t) {
            s3[i] = s1[i];
            c++;
        }
    }
    if(c == t) {
        for(i=0; i<n; i++) {
            if(s3[i] == ' ') {
                s3[i] = 'a';
                if(s3[i] == s1[i]) s3[i]++;
                if(s3[i] == s2[i]) s3[i]++;
                if(s3[i] == s1[i]) s3[i]++;
            }
        }
        cout << s3 << "\n";
        return;
    }
    int c1 = c, c2 = c;
    for(i=0; i<n; i++) {
        if(s3[i] != ' ')
            continue;
        if(c1 < t) {
            s3[i] = s1[i];
            c1++;
        }
        else if(c2 < t) {
            s3[i] = s2[i];
            c2++;
        }
        else {
            s3[i] = 'a';
            if(s3[i] == s1[i]) s3[i]++;
            if(s3[i] == s2[i]) s3[i]++;
            if(s3[i] == s1[i]) s3[i]++;
        }
    }
    if(c1 != t || c2 != t)
        cout << -1 << "\n";
    else
        cout << s3 << "\n";
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
