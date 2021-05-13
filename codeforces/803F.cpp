#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3;
const int mod = 1e9 + 7;
int two[mxn], cnt[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    while(n--) {
    	int x; cin >> x;
    	cnt[x]++;
    }
    two[0] = 1;
    for(int i = 1; i < mxn; i++) {
    	two[i] = (two[i - 1] << 1) % mod;
    	for(int j = 2 * i; j < mxn; j += i)
    		(cnt[i] += cnt[j]) %= mod;  //no. of elements divisible by i
    }
    for(int i = 1; i < mxn; i++)
    	cnt[i] = two[cnt[i]] - 1; //subsequences divisible by i
    for(int i = mxn - 1; i; i--)
    	for(int j = 2 * i; j < mxn; j += i)
    		cnt[i] = (cnt[i] - cnt[j] + mod) % mod;  //subsequences divisible only by i
    cout << cnt[1] << '\n';
    return 0;
}