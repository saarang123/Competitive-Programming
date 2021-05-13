#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) 
    	cin >> a[i];
    auto best = [&] (vector<int> h) {
        int ans = 0, i = 0;
        stack<int> s;
        while(i <= n) {
            if(s.empty() || h[s.top()] <= h[i])
                s.push(i++);
            else {
                int md = s.top(); s.pop();
                ans = max(ans, (s.empty() ? i : i - s.top() - 1) * h[md]);
            }
        }
        while(!s.empty()) {
            int md = s.top(); s.pop();
            ans = max(ans, (s.empty() ? i : i - s.top() - 1) * h[md]);
        }
        return ans;
    };
    cout << best(a) << '\n';
    return 0;
}