#include <bits/stdc++.h>
using namespace std;
const int MXN = 100 * 1000 + 3;
const int C = 320;
int cnt[C][MXN], a[MXN], blk[MXN];
deque<int> dq[C];
int n, q, ans = 0;

void upd(int l, int r) {
	int x = dq[blk[r]][r % C];
	dq[blk[r]].erase(dq[blk[r]].begin() + r % C);
	cnt[blk[r]][x]--; cnt[blk[l]][x]++;
	dq[blk[l]].insert(dq[blk[l]].begin() + l % C, x);
	for(int i = blk[l]; i < blk[r]; i++) {
		dq[i + 1].push_front(dq[i].back());
		cnt[i][dq[i].back()]--; cnt[i + 1][dq[i].back()]++;
		dq[i].pop_back();
	}
}

int query(int l, int r, int k) {
	ans = 0;
	if(blk[l] == blk[r]) 
		for(int i = l; i <= r; i++)
			ans += dq[blk[l]][i % C] == k;
	else {
		for(int i = l; i < blk[l] * C + C; i++)
			ans += dq[blk[l]][i % C] == k;
		for(int i = blk[l] + 1; i < blk[r]; i++)
			ans += cnt[i][k];
		for(int i = blk[r] * C; i <= r; i++)
			ans += dq[blk[r]][i % C] == k;
	}
	return ans;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	blk[i] = i / C;
    	cnt[blk[i]][a[i]]++;
    	dq[blk[i]].push_back(a[i]);
    }
    cin >> q;
    while(q--) {
    	int tp, l, r;
    	cin >> tp >> l >> r;
    	l = (n + l + ans - 1) % n;
    	r = (n + r + ans - 1) % n;
    	if(l > r)
    		swap(l, r);
    	if(tp == 1) {
    		upd(l, r);
    	} else {
    		int k; cin >> k;
    		k = (n + k + ans - 1) % n + 1;
    		cout << query(l, r, k) << '\n';
    	}
    }
    return 0;
}