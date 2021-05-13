#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool cmp(array<ll, 2> x, array<ll, 2> y) {
	if(x[0] != y[0]) return (x[0] < y[0]);
	return (x[1] > y[1]);
}

const int N = 5002;
int n, c;
ll ans = 0;
vector<int> s, v;

void calc(vector<array<ll, 2>> &a, int x, int j) {
	for(int mask = 0; mask < (1 << x); mask++) {
		ll sum = 0, val = 0;
		bool flag = 1;
		for(int i = 0; i < x; i++) {
			if(mask >> i & 1) sum += s[i + j], val += v[i + j];
			if(sum > c) {
				flag = 0; break;
			}
		}
		if(flag && sum <= c) { a.push_back({sum, val}); ans = max(ans, val); }
	}
}

ll solve() {
	vector<array<ll, 2>> l, r;
	calc(l, n / 2, 0);
	calc(r, n - n / 2, n / 2);
	//for(auto x : l) cout << x[1] << ' '; cout << '\n';
	//for(auto x : r) cout << x[1] << ' '; cout << '\n';
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	if(l.size() < r.size()) swap(l, r);
	reverse(l.begin(), l.end());
	int mx = 0, j = 0, sz = r.size();
	for(auto tx : l) {
		int sum = tx[0], val = tx[1];
		while(j < sz && sum + r[j][0] <= c) {
			mx = max(mx, r[j++][1]);
		}
		ans = max(ans, val + mx);
	}
	return ans;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    cin >> n >> c;
    for(int x, y, i = 0; i < n; i++) {
    	cin >> x >> y;
    	if(x <= c) {
    		s.push_back(x); v.push_back(y);
    	}
    }
    n = s.size();
    cout << solve() << '\n';
    return 0;
}
