#include <bits/stdc++.h>
using namespace std;
const int LIM = 1e5, B = 350, NB = LIM/B + 2, SZ = LIM * 2 + 2;

int v[LIM], toAdd[NB], cnt[NB][SZ];

int n, a[LIM];
long long ans = 0;

void add(int i, int val){
	int k = i/B;
	for(int j=i; j/B == k && j < n; ++j){
		--cnt[k][LIM + v[j]];
		v[j] += val;
		++cnt[k][LIM + v[j]];
	}
	++k;
	for(; k*B < n; ++k) toAdd[k] += val;
}

int getFreq(int i, int val){
	int k = i/B, res = 0;
	for(int j=i; j/B == k && j < n; ++j){
		res += (v[j] + toAdd[k]) == val;
	}
	++k;
	for(; k*B < n; ++k) if(LIM + val - toAdd[k] < SZ) res += cnt[k][LIM + val - toAdd[k]];
	return res;
}

void solve(){
	iota(v, v+n, 1);
	for(int i=0; i<n; ++i) ++cnt[i/B][LIM + v[i]];
	int pos[n];
	for(int i=0; i<n; ++i) pos[a[i]] = i;

	for(int i : pos){
		int val = i ? v[i-1] + toAdd[(i-1)/B] : 0LL;
		ans += getFreq(i, val);
		ans += getFreq(i, val + 1);
		add(i, -2);
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef saarang
	freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
	freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
	#endif
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i], --a[i];

	solve();
	reverse(a, a+n);
	fill(toAdd, toAdd+NB, 0LL);
	for(int i=0; i<NB; ++i) fill(cnt[i], cnt[i]+SZ, 0LL);
	solve();
	
	cout << ans - n << '\n';
}