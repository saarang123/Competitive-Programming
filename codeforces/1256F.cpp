#include <bits/stdc++.h>
using namespace std;

bool inv_parity(string s) {
    bool ans = 0;
    for(int i = 0; i < s.size(); i++)
        for(int j = 0; j < i; j++)
            if(s[j] > s[i])
                ans ^= 1;
    return ans;
}

void solve_case() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    bool ok = 0;
    vector<int> f(26);
    for(char c : s) f[c - 'a']++;
    for(int x : f) if(x >= 2) ok = true;
    for(char c : t) f[c - 'a']--;
    for(int x : f) if(x != 0) return void(cout << "NO\n");
    if(ok) cout << "YES\n";
    else if(inv_parity(s) != inv_parity(t)) cout << "NO\n";
    else cout << "YES\n";
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
