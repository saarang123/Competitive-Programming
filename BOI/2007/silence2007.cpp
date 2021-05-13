#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n,i,m,c,j;
    cin >> n >> m >> c;
    vector<int> a(n + 1);
    for(i = 0; i < n; i++)
        cin >> a[i];
    a[n] = -1;
    multiset<int> st;
    vector<int> ans;
    for(i = n - 1; i >= 0; i--) {
        if(i + m > n) {
            st.insert(a[i]);
            continue;
        }
        if(st.count(a[i + m])) st.erase(st.find(a[i + m]));
        st.insert(a[i]);
        int x = *st.begin(), y = *st.rbegin();
        if(y - x <= c)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    if(ans.empty())
        return cout << "NONE" << endl, 0;
    for(int id : ans) cout << id + 1 << " "; cout << endl;
    return 0;
}
