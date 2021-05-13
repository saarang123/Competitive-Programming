#include <bits/stdc++.h>
using namespace std;
const int MXN = 100 * 1000 + 3;
const int SQT = 320;
int p[MXN], jump[MXN], cnt[MXN];
int n, m;

void compute(int i) {
	int start = i - i % SQT;
	int end = min(n, start + SQT);
	int nxt = i + p[i];
	if(nxt >= n) {
		jump[i] = i;
		cnt[i] = 0;
	} else if(nxt >= end) {
		jump[i] = nxt;
		cnt[i] = 1;
	} else {
		jump[i] = jump[nxt];
		cnt[i] = 1 + cnt[nxt];
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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    	cin >> p[i];
    for(int i = n - 1; i >= 0; i--)
    	compute(i);
    while(m--) {
    	int tp; cin >> tp;
    	if(tp) {
    		int x; cin >> x; x--;
    		int ans = 1;
    		while(x != jump[x]) {
    			ans += cnt[x];
    			x = jump[x];
    		}
    		cout << x + 1 << ' ' << ans << '\n';
    	} else {
    		int a, b;
    		cin >> a >> b; a--;
    		p[a] = b;
    		for(int i = a; i >= a - a % SQT; i--)
    			compute(i);
    	}
    }
    return 0;
}