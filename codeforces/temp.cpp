#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
bool prime[N];

void init() {
    prime[1] = 1;
    for(long long int i=2; i<N; i++) {
        if(prime[i]) continue;
        for(long long int j=2; j*i<N; j++)
            prime[i*j] = 1;
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    init();
    int n; cin >> n;
    vector<int> d(n + 1), dp(n + 1);
    for(int i = 0; i < n; i++)
        cin >> d[i];
    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> ok;
        int i = 0, sum = d[0];
        for(; i < n;) {
            sum = d[i];
            while(i < n && !(mask >> i & 1))
                sum += d[i++];
            ok.push_back(sum);
        }
        bool flag = 1;
        for(int x : ok) {
            flag = flag && !(prime[x]);
        }
        if(flag)
            ans = max(ans, (int) ok.size());
    }
    cout << ans << '\n';
    return 0;
}