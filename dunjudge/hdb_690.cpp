#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const int N = 100 * 1000 + 3;
int a[N], n, l;
vector<int> t[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> l;
    for(int i = 1, x; i <= n; i++) {
    	cin >> a[i] >> x;
    	while(x--) {
    		int k; cin >> k;
    		t[i].push_back(k);
    	}
    	sort(t[i].begin(), t[i].end());
    }
    t[n].push_back(l);
    int sz = t[1].size();
    vector<long long> dp(sz), pref(sz), suf(sz);
    for(int i = 0; i < sz; i++) {
    	dp[i] = a[1] * (t[1][i] - 1);
    	pref[i] = dp[i] - (a[2] * t[1][i]);
    	suf[i] = dp[i] + (a[2] * t[1][i]);
    	if(i)
    		pref[i] = min(pref[i], pref[i - 1]);
    }
    for(int i = sz - 2; i >= 0; i--)
    	suf[i] = min(suf[i + 1], suf[i]);
    for(int i = 2; i <= n; i++) {
    	int s = t[i].size();
    	vector<long long> curdp(s);
    	for(int j = 0; j < s; j++) {
    		curdp[j] = inf;
    		auto id = upper_bound(t[i - 1].begin(), t[i - 1].end(), t[i][j]) - t[i - 1].begin();
    		if(id < t[i - 1].size())
    			curdp[j] = min(curdp[j], suf[id] - a[i] * t[i][j]);
    		id--;
    		if(id >= 0 && id < t[i - 1].size() && t[i - 1][id] <= t[i][j])
    			curdp[j] = min(curdp[j], pref[id] + a[i] * t[i][j]);
    	}
    	dp = curdp;
    	pref.resize(s); suf.resize(s);
    	for(int j = 0; j < s; j++) {
    		pref[j] = dp[j] - (a[i + 1] * t[i][j]);
    		suf[j] = dp[j] + (a[i + 1] * t[i][j]);
    		if(j)
    			pref[j] = min(pref[j], pref[j - 1]);
    	}
    	for(int j = s - 2; j >= 0; j--)
    		suf[j] = min(suf[j], suf[j + 1]);
    }
    cout << dp.back() << '\n';
    return 0;
}