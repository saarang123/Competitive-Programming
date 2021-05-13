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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for(i=0; i<n; i++) {
        cin >> j;
        pq.push(mp(j, i));
    }
    if(n==1) {
        cout << "T" << "\n";
        return;
    }
    int prev = -1;
    bool winner = 1;
    while(pq.size() > 1) {
        pair<int, int> a = pq.top();
        pq.pop();
        if(a.second == prev) {
            pair<int, int> b = pq.top();
            pq.pop();
            b.first--;
            pq.push(a);
            if(b.first) pq.push(b);
            prev = b.second;
        }
        else {
            a.first--;
            if(a.first) pq.push(a);
            prev = a.second;
        }
        winner ^= 1;
    }
    if(winner) cout << "T" << "\n";
    else cout << "HL" << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
