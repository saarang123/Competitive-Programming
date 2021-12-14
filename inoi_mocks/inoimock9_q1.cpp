#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> a(q);
    vector<int> p(n);
    int id = 1;
    for(auto &[l, r, i] : a) {
    	cin >> l >> r >> i;
    	l--, r--, i--;
    	p[i] = id++;
    	for(int j = l; j <= r; j++) if(j != i)
    		p[j] = id++;
    }
    for(int i = 0; i < n; i++)
    	cout << p[i] << ' ';
    cout << '\n';
    return 0;
}