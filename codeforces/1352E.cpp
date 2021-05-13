#include <bits/stdc++.h>
using namespace std;

const int N = 8001;
bitset<N> can;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int t, n, i, j;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        can.reset();
        for(int &x : a) cin >> x;
        for(i = 0; i < n; i++) {
            int sum = a[i];
            for(j = i + 1; j < n; j++) {
                sum += a[j];
                if(sum > n) break;
                can[sum] = 1;
            }
        }
        int x = 0;
        for(int tx : a) x += can[tx];
        cout << x << endl;
    }
    return 0;
}
