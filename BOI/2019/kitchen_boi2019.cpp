#include <bits/stdc++.h>
using namespace std;
const int N = 302;
const int inf = 1000 * 1000 * 1000;

template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	#ifdef saarang
	freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
	freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	cin >> a; cin >> b;
	if(*min_element(a.begin(), a.end()) < k)
		return cout << "Impossible" << '\n', 0;
	vector<int> dp(N * N, -1);
	dp[0] = 0;
	for(int i = 0; i < m; i++) {
		for(int j = m * N - b[i]; j >= 0; j--)
			if(dp[j] != -1)
				dp[j + b[i]] = max(dp[j + b[i]], dp[j] + min(b[i], n));
	}
	int answer = inf;
	int sum = accumulate(a.begin(), a.end(), 0);
	for(int i = sum; i < N * N; i++)
		if(dp[i] >= n * k)
			answer = min(answer, i - sum);
	cout << (answer ^ inf ? to_string(answer) : "Impossible") << '\n';
}