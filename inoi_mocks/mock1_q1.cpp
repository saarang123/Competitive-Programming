#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, q, time = 0, seen = 0;
    cin >> n >> q;
    vector<int> tin(n, -1), tout(n, -1);
    stack<int> st;
    for(int i = 0, t, a; i < n; i++) {
        cin >> t;
        if(t == 2) {
            int x = st.top(); st.pop();
            tout[x] = seen;
        } else {
            cin >> a; a--;
            st.push(a);
            tin[a] = seen++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(tin[i] != -1 && tout[i] == -1) tout[i] = seen;
        if(tin[i] == -1) tin[i] = seen;
    }
    //for(int x : tin) cout << x << ' '; cout << endl;
    //for(int x : tout) cout << x << ' '; cout << endl;
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(tin[a] == -1 || tin[b] == -1) cout << 0 << '\n';
        else {
            cout << max(0, min(tout[a], tout[b]) - max(tin[a], tin[b])) << '\n';
        }
    }
    return 0;
}