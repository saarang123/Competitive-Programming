#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int X = 1e7+2;
const int N = 1e6+2;
int spf[X], a[N];
map<int, int> cnt;
void sieve() {
    spf[1] = 1;
    for (int i=2; i<X; i++)
        spf[i] = i;
    for (int i=4; i<X; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<X; i++) {
        if (spf[i] == i) {
            for (int j=i*i; j<X; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void fct(int x) {
    set<int> nxt;
    while (x != 1) {
        if(!nxt.count(spf[x])) cnt[spf[x]]++;
        nxt.insert(spf[x]);
        x = x / spf[x];
    }
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    sieve();
    cin >> n;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        fct(a[i]);
        //cout << spf[a[i]] << " is spf\n";
    }
    /*
    for(auto p: cnt) {
        cout << "prime: " << p.first << " " << "count: " << p.second << "\n";
    }*/
    vector<pair<int,int>> ans;
    ans.pb(mp(0,0));
    for(auto p: cnt) ans.pb(p);
    ans.pb(mp(2e9+2,0));
    for(i=1; i<ans.size(); i++) {
        ans[i].second += ans[i-1].second;
    }
    int m; cin >> m;
    while(m--) {
        int l,r;
        cin >> l >> r;
        i = lower_bound(all(ans), mp(l, -1)) - ans.begin();
        j = upper_bound(all(ans), mp(r,-1)) - ans.begin();
        if(i) i--;
        if(j < ans.size()-1 && ans[j].first > r) j--;
        //cout << ans[i].first << " " << ans[i].second << "\n";
        //cout << ans[j].first << " " << ans[j].second << "\n";
        cout << ans[j].second-ans[i].second << "\n";
        //cout << "------------------\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
