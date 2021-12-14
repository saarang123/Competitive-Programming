#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <stack>
#include <queue>
#include <random>
#include <numeric>
#include <functional>
#include <chrono>
#include <utility>
#include <bitset>
#include <iomanip>
#include <assert.h>

using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;

template<typename S, typename T> void smax(S &a, const T &b) { if (a < b) a = b; }
template<typename S, typename T> void smin(S &a, const T &b) { if (a > b) a = b; }

#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rng_seed(x) mt19937 rng(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
// #define int long long

const int MXN = 1e5 + 5, INF = 1e9 + 5;

void solve() {
    int N, K;
    cin >> N >> K;

    set<array<int, 3>> saarang, shiven;
    pair<int, int> saarang_store[N], shiven_store[N];

    vector<int> dist(2 * N, -1);
    queue<int> q;
    for (int i = 0; i < N; i++) {
        int d1, d2;
        cin >> d1 >> d2;

        saarang_store[i] = make_pair(d1, d2);

        if (d2 == 0) {
            dist[i] = 1;
            q.push(i);
        } else saarang.emplace(array<int, 3>{d2, d1, i});
    }

    for (int i = 0; i < N; i++) {
        int d1, d2;
        cin >> d1 >> d2;

        shiven_store[i] = make_pair(d1, d2);

        if (d1 == 0) {
            dist[i + N] = 1;
            q.push(i + N);
        } else shiven.emplace(array<int, 3>{d1, d2, i + N});
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u < N) {
            int cap = saarang_store[u].first - K;
            auto it = shiven.lower_bound(array<int, 3>{cap, -1, -1});

            while (it != shiven.end()) {
                if ((*it)[0] > cap + K) break;

                int v = (*it)[2];
                bool increment = true;

                if ((dist[v] == -1) || (dist[v] > dist[u] + 1)) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    it = shiven.erase(it);
                    increment = false;
                }

                if (it != shiven.end() && increment) it++;
            }
        } else {            
            int cap = shiven_store[u - N].second - K;
            auto it = saarang.lower_bound(array<int, 3>{cap, -1, -1});

            while (it != saarang.end()) {
                if ((*it)[0] > cap + K) break;

                int v = (*it)[2];
                bool increment = true;

                if ((dist[v] == -1) || (dist[v] > dist[u] + 1)) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    it = saarang.erase(it);
                    increment = false;
                }

                if (it != saarang.end() && increment) it++;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << dist[i] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    while (TC--) solve();
}