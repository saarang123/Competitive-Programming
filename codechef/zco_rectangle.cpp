#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    vector<int> a(N + 1, 500);
    int n; cin >> n;
    for(int x, y, i = 0; i < n; i++) {
    	cin >> x >> y;
    	a[x] = min(a[x], y);
    }
    auto best = [&] (vector<int> h) {
        int ans = 0, i = 0;
        stack<int> s;
        while(i <= N){
            if(s.empty() or h[s.top()] <= h[i]) s.push(i++);
            else{
                int mid = s.top(); s.pop();
                ans = max(ans, (s.empty() ? i : i - s.top()) * h[mid]);
            }
        }
        while(!s.empty()){
            int mid = s.top(); s.pop();
            ans = max(ans, (s.empty() ? N : N - s.top()) * h[mid]);
        }
        return ans;
    };
    cout << best(a) << '\n';
    return 0;
}