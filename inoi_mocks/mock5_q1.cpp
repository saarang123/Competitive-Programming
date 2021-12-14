#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, q;
    cin >> n >> q;
    priority_queue<long long, vector<long long>, greater<>> pq;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
    long long offset = 0;
    while(q--) {
        char c; cin >> c;
        int x; cin >> x;
        if(c == 'A') {
            offset += x;
            while(!pq.empty() && pq.top() - offset <= 0)
                pq.pop();
        } else {
            if(!pq.empty()) {
                int y = pq.top();
                pq.pop();
                pq.push(y + x);
            }
        }
    }
    cout << n - pq.size() << '\n';
    return 0;
}