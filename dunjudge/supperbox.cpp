#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MXN = 10 * 1000 + 3;
const int MXQ = 5 * MXN;
const int MX = 2003;
int dp1[MXN][MX], dp2[MXN][MX], L[MXQ], R[MXQ], X[MXQ], C[MXN], S[MXN], ans[MXQ];
int N, Q;

void dnc_srq(int l, int r, vector<int> &queries) {
	if(queries.empty())
		return;
	if(l == r) {
		for(const auto &id : queries)
			if(C[l] <= X[id])
				ans[id] = S[l];
		return;
	}
	int mid = (l + r) >> 1;
	for(int i = mid; i >= l; i--) 
		for(int j = 1; j < MX; j++) {
			dp1[i][j] = max(dp1[i + 1][j], dp1[i][j - 1]);
			if(j - C[i] >= 0)
				dp1[i][j] = max(dp1[i][j], dp1[i + 1][j - C[i]] + S[i]);
		}

	for(int i = mid + 1; i <= r; i++) 
		for(int j = 1; j < MX; j++) {
			dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
			if(j - C[i] >= 0)
				dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - C[i]] + S[i]);
		}

	vector<int> newQ[2];
	for(const auto &id : queries) {
		if(L[id] <= mid && mid < R[id]) {
			for(int i = 0; i <= X[id]; i++)
				ans[id] = max(ans[id], dp1[L[id]][i] + dp2[R[id]][X[id] - i]);
			continue;
		}
		newQ[L[id] > mid].push_back(id);
	}
	for(int i = l; i <= r; i++) {
		memset(dp1[i], 0, sizeof dp1[i]);
		memset(dp2[i], 0, sizeof dp2[i]);
	}
	dnc_srq(l, mid, newQ[0]);
	dnc_srq(mid + 1, r, newQ[1]);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> C[i] >> S[i];
    cin >> Q;
    for(int i = 0; i < Q; i++)
    	cin >> L[i] >> R[i] >> X[i];
    vector<int> queries(Q);
    iota(queries.begin(), queries.end(), 0);

    dnc_srq(1, N, queries);

    for(int i = 0; i < Q; i++)
    	cout << ans[i] << '\n';
    return 0;
}