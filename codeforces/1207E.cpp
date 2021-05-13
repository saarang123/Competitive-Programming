#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

vector<int> one, two;
int mx = (1<<14);

int ask(vector<int> a) {
    cout << "? ";
    for(int i=0; i<100; i++) cout << a[i] << " ";
    cout << endl;
    cout.flush();
    int tmp; cin >> tmp;
    return tmp;
}

void solve_case() {
    // :pray: :fishy: :orz:
    int i, x = 0;
    for(int mask=0; mask<mx; mask++) {
        int pos = 1;
        for(i=0; i<7; i++) {
            if(!(mask & (1<<i)))
                pos = 0;
        }
        if(pos) {
            one.pb(mask);
            continue;
        }
        pos = 1;
        for(i=7; i<14; i++) {
            if(!(mask & (1<<i)))
                pos = 0;
        }
        if(pos)
            two.pb(mask);
    }
    int a = ask(one);
    for(i=0; i<7; i++) {
        if(!(a & (1<<i))) {
            x += (1<<i);
        }
    }
    a = ask(two);
    for(i=7; i<14; i++) {
        if(!(a & (1<<i)))
            x += (1<<i);
    }
    cout << "! " << x << endl;
    cout.flush();
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
