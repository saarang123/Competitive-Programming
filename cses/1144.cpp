#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key (k) : Number of items strictly smaller than k 
//find_by_order(k) : K-th element in a set (counting from zero)
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    oset<array<int, 2>> ost;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	ost.insert({a[i], i});
    }
    while(q--) {
    	char c; cin >> c;
    	int k, x;
    	cin >> k >> x;
    	if(c == '!') {
    		ost.erase({a[k], k});
    		a[k] = x;
    		ost.insert({a[k], k});
    	} else {
    		int cnt = ost.order_of_key({x + 1, 0}) - ost.order_of_key({k, 0});
    		cout << cnt << '\n';
    	}
    }
    return 0;
}