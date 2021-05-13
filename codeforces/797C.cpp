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

int f[26];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    string s;
    cin >> s;
    n = s.size();
    for(char c: s)
        f[c-'a']++;
    string u;
    stack<char> q;
    i = 0;
    while(u.size() < n) {
        int mx = -1;
        for(j=0; j<26; j++) {
            if(f[j]) {
                mx = j;
                break;
            }
        }
        if(mx == -1)
            break;
        while(!q.empty() && q.top() <= char('a' + mx)) {
            u += q.top();
            q.pop();
        }
        while(i < n && s[i] != char('a' + mx)) {
            f[s[i]-'a']--;
            q.push(s[i++]);
        }
        f[s[i]-'a']--;
        u += s[i++];
    }
    while(!q.empty()) {
        u += q.top();
        q.pop();
    }
    cout << u << "\n";
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
