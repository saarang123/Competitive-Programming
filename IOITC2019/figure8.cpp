#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pt pair<int,int>
#define X first
#define Y second
int dot(const pt &a, const pt &b) { return (a.X*b.X) + (a.Y*b.Y); }
int cross(const pt &a, const pt &b) { return (a.X*b.Y) - (b.X*a.Y); }	
pt operator-(const pt &a, const pt &b) { return pt(a.X - b.X, a.Y - b.Y); }
int norm(const pt &a) { return (a.X*a.X) + (a.Y*a.Y); }

vector<int> chull(vector<pt> &v) {
    int ind = min_element(v.begin(), v.end()) - v.begin();
    vector<int> cand, hull = {ind};
    for (int i = 0; i < v.size(); i++) if (v[i] != v[ind]) cand.push_back(i);
    sort(cand.begin(), cand.end(), [&](int a, int b) {
        pt p1 = v[a] - v[ind], p2 = v[b] - v[ind];
        int t = cross(p1, p2);
        if (t == 0) return norm(p1) < norm(p2);
        return t > 0;
    });
    for (int i : cand) {
        while (hull.size() > 1 && cross(v[end(hull)[-1]] - v[end(hull)[-2]], v[i] - v[end(hull)[-2]]) <= 0) 
            hull.pop_back();
        hull.push_back(i);
    }
    return hull;
}

using ld = long double;
const ld eps = 1e-9;
struct Line {
	ld m, c;
	Line(ld _m, ld _c) : m(_m), c(_c) {}
	Line() : m(0), c(0) {}
	ld operator() (int x) { return m * x + c; }
};

void solve() {
	int n; cin >> n;
	vector<pt> a(n);
	for(auto &x : a)
		cin >> x.X >> x.Y;
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			vector<pt> up, down;
			Line to; to.m = ((ld) a[i].Y - a[j].Y) / ((ld) a[i].X - a[j].X);
			to.c = (ld) a[i].Y - a[i].X * to.m;
			//assert(abs((ld) a[j].Y - a[j].X * to.m - to.c) <= eps);
			for(int k = 0; k < n; k++) if(k != i && k != j) {
				pt p = a[k];
				if(to(p.X) >= p.Y)
					down.push_back(p);
				else
					up.push_back(p);
			}
			up.push_back(a[i]); up.push_back(a[j]);
			down.push_back(a[i]); down.push_back(a[j]);
			int one = chull(up).size(), two = chull(down).size();
			ans = max(ans, one + two - 2);
		}
	cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tc; cin >> tc;
    while(tc--) 
    	solve();
    return 0;
}