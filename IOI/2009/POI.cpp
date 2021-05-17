#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> scores(t, n);
    vector<vector<int>> a(n, vector<int> (t));
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < t; j++) {
    		cin >> a[i][j];
    		scores[j] -= a[i][j];
    	}
    vector<array<int, 3>> rank;
    for(int i = 0; i < n; i++) {
    	int sum = 0, cnt = 0;
    	for(int j = 0; j < t; j++)
    		if(a[i][j])
    			sum += scores[j], cnt++;
    	rank.push_back({sum, cnt, i + 1});
    }
    sort(rank.begin(), rank.end(), [&] (array<int, 3> x, array<int, 3> y) {
    	if(x[0] != y[0])
    		return x[0] > y[0];
    	if(x[1] != y[1])
    		return x[1] > y[1];
    	return x[2] < y[2];
    });
    int position = -1, sum = 0;
    for(int i = 0; i < n; i++) 
    	if(rank[i][2] == p)
    		position = i + 1, sum = rank[i][0];
    cout << sum << ' ' << position << '\n';
    return 0;
}