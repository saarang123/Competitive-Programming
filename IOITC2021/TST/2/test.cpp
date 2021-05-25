#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("in.txt", "w", stdout);
    int tc = rng() % 10;
    cout << tc << '\n';
    while(tc--) {
    	int n = 1 + rng() % 10;
    	int m = n - 1;
    	cout << n << ' ' << m << '\n';
    	vector<int> perm(m), p(m);
    	iota(perm.begin(), perm.end(), 0);
    	shuffle(perm.begin(), perm.end(), rng);
    	for(int i = 0; i < m; i++) {
    		cout << perm[i];
    		if(i != m - 1)
    			cout << ' ';
    	}
    	if(m)
    		cout << '\n';
    	for(int i = 1; i < n; i++) {
    		int par = rng() % i;
    		cout << i << ' ' << par << '\n';
    	}
    }
    return 0;
}