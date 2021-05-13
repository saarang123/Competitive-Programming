#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
	#endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

vector<int> id;
vector<array<int, 3>> a;
int n;

void calc() {
	sort(all(a));
	set<array<int, 2>> h;
	for(int i = 0, j = 0; i < n && j < n; i = j) {
		while(j < n && a[i][0] == a[j][0]) j++;
		for(int k = i; k < j; k++) {
			if(h.empty()) continue;
			auto mn = *h.begin();
			if(mn[0] < a[k][1]) id[a[k][2]] = mn[1] + 1;
		}
		for(int k = i; k < j; k++) h.insert({a[k][1], a[k][2]});
	}
}

void solve_case() {
    cin >> n;
    a.resize(n); id.assign(n, -1);
    int i = 0;
    for(auto &x : a) {
    	cin >> x[0] >> x[1], x[2] = i++;
    	if(x[0] > x[1]) swap(x[0], x[1]);
    }
    calc();
	for(int x : id) cout << x << ' '; cout << '\n';
}
