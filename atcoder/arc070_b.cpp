#include <bits/stdc++.h>
using namespace std;
const int mxn = 5003;
int a[mxn], n, k;
bitset<mxn> p[mxn], s[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> a[i], a[i] = min(a[i], k);
    p[0][0] = 1;
    s[n + 1][0] = 1;
    for(int i = 1; i <= n; i++)
    	p[i] = p[i - 1] | (p[i - 1] << a[i]);
    for(int i = n; i; i--)
    	s[i] = s[i + 1] | (s[i + 1] << a[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++) if(a[i] < k) {
    	vector<int> cnt(k + 2);
    	for(int j = 0; j <= k; j++)
    		if(p[i - 1][j])
    			cnt[j]++;
    	for(int j = 1; j <= k; j++)
    		cnt[j] += cnt[j - 1];
    	bool flag = true;
    	for(int j = 0; j <= k; j++) if(s[i + 1][j]) {
    		int l = k - a[i] - j;
    		int r = k - 1 - j;
    		if(r < 1) continue;
    		l = max(l, 1);
    		if(cnt[r] - cnt[l - 1] > 0) {
    			flag = false;
    			break;
    		}
    	}
    	for(int j = k - a[i]; j < k; j++) if(p[i - 1][j] || s[i + 1][j])
    		flag = false;
    	ans += flag;
    }
    cout << ans << '\n';
    return 0;
}