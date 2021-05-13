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

const int N = (1<<10)+3;
vector<int> a[N];
int f[N];

void ask(int i, int j) {
    for(int u: a[i]) {
        cout << "? " << u << endl;
        cout.flush();
        char c;
        cin >> c;
        if(c=='Y') f[u] = 1;
    }
    for(int u: a[j]) {
        cout << "? " << u << endl;
        cout.flush();
        char c;
        cin >> c;
        if(c=='Y') f[u] = 1;
    }
    cout << "R" << endl;
    cout.flush();
}

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,k;
    cin >> n >> k;
    if(k>1) k/=2;
    int cnt = 0;
    j = 1;
    for(i=1; i<=n; i++) {
        a[j].pb(i);
        cnt++;
        if(cnt==k) cnt=0, j++;
    }
    if(a[j].empty()) j--;
    /*
    for(i=1; i<=j; i++) {
        cout << i << ": " << endl;
        for(int u: a[i]) cout << u << " "; cout << "\n";
    }*/

    for(i=1; i<=j; i++) {
        for(int l=i+1; l<=j; l++) {
            ask(i,l);
        }
    }
    cnt = 0;
    for(i=1; i<=n; i++) cnt += (f[i]==0);
    cout << "! " << cnt << endl;
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
