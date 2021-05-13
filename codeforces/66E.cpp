#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    set<int> st;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int dist = 0, time = 0, sub = 0;
    for(int i = 0; i < n; i++) {
        dist += a[i];
        time += b[i];
        st.insert(dist - time);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(*st.begin() - sub >= 0)
            ans.push_back(i + 1);
        sub += a[i] - b[i];
    }
    st.clear();
    dist = 0, time = 0, sub = 0;
    for(int i = n - 1; i >= 0; i--) {
        dist += a[(i + 1) % n];
        time += b[i];
        st.insert(dist - time);
    }
    sub = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(*st.begin() - sub >= 0)
            ans.push_back((i + 1) % n + 1);
        sub += a[(i + 1) % n] - b[i];
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for(int id : ans) cout << id << ' '; cout << endl;
    return 0;
}
