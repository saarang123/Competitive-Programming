#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = (int)3e5 + 5;

namespace bit {
  ll b[N], n;

  void init(int _n) {
    n = _n;
    fill(b, b + n + 1, 0);
  }
  inline int lowbit(int x) {
    return x & (-x);
  }
  void upd(int x, int v) {
    for(int i = x ; i <= n ; i += lowbit(i)) b[i] += v;
  }
  void update(int l, int r, int v) {
    upd(r + 1, -v), upd(l, v);
    if(l > r) upd(1, v), upd(n + 1, -v);
  }
  ll query(int x) {
    ll ans = 0;
    for(int i = x ; i > 0 ; i -= lowbit(i)) ans += b[i];
    return ans;
  }
}

int n, m, k, target[N], ans[N];
vector<tuple<int, int, int> > event;
vector<int> lands[N];

void totBS(int l, int r, vector<int>& candi) {
  if(l + 1 == r || candi.empty()) {
    for(auto c : candi) ans[c] = l;
    return;
  }
  int mid = (l + r) >> 1;
  // do things: events from [l, mid)
  for(int i = l ; i < mid ; ++i) {
    auto [el, er, ea] = event[i];
    bit::update(el, er, ea);
  }
  // split candi into two parts
  vector<int> ok, not_ok;
  for(auto c : candi) {
    ull sum = 0;
    for(auto land : lands[c]) sum += bit::query(land);
    if(sum >= (ull)target[c]) ok.push_back(c);
    else {
      target[c] -= sum;
      not_ok.push_back(c);
    }
  }
  // undo things
  for(int i = l ; i < mid ; ++i) {
    auto [el, er, ea] = event[i];
    bit::update(el, er, -ea);
  }
  // continue binary search and free memory
  totBS(l, mid, ok); vector<int> ().swap(ok);
  totBS(mid, r, not_ok); vector<int> ().swap(not_ok);
}

void init() {
  cin >> n >> m;
  for(int i = 1 ; i <= m ; ++i) {
    int x; cin >> x; lands[x].push_back(i);
  }
  for(int i = 1 ; i <= n ; ++i) cin >> target[i];
  cin >> k;
  for(int i = 0 ; i < k ; ++i) {
    int l, r, a; cin >> l >> r >> a;
    event.push_back({l, r, a});
  }
}
void solve() {
  bit::init(m);
  vector<int> all; 
  for(int i = 1 ; i <= n ; ++i) all.push_back(i);
  totBS(0, k + 1, all);
  vector<int> ().swap(all);
  for(int i = 1 ; i <= n ; ++i) {
    if(ans[i] == k) cout << "NIE\n";
    else cout << ans[i] + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  #ifdef saarang
  freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
  freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
  #endif
  init();
  solve();
}