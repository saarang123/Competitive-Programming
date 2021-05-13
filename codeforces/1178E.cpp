#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    string s; cin >> s;
    int n = s.size();
    int i = 0, j = n - 2;
    vector<char> front, back;
    while(i + 1 < j) {
    	if(s[i] == s[j] || s[i] == s[j + 1]) {
    		front.push_back(s[i]);
    		back.push_back(s[i]);
    	} else {
    		front.push_back(s[i + 1]);
    		back.push_back(s[i + 1]);
    	}
    	i += 2;
    	j -= 2;
    }
    if(i - 1 <= j) //middle
    	front.push_back(s[i]);
    string ans = "";
    for(char c : front)
    	ans += c;
    reverse(back.begin(), back.end());
    for(char c : back)
    	ans += c;
    if(ans.size() < n/2)
    	cout << "IMPOSSIBLE" << '\n';
    else {
    	string rev = ans;
    	reverse(rev.begin(), rev.end());
    	if(ans != rev)
    		cout << "IMPOSSIBLE" << '\n';
    	else
    		cout << ans << '\n';
    }
    return 0;
}