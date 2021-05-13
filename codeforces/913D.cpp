#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, k, i, j;
    cin >> n >> k;
    vector<array<int, 3>> a(n);
    vector<int> ans;
    for(i = 0; i < n; i++)
        cin >> a[i][1] >> a[i][0], a[i][2] = i;
    sort(a.begin(), a.end());
    int mn = 0, mx = n, m = 0;
    while(mn < mx) {
        int mid = (mn + 1 + mx) >> 1;
        vector<int> id;
        for(i = 0; i < n; i++)
            if(a[i][1] >= mid)
                id.push_back(i);
        bool ok = false;
        //cout << "Binsearch: " << mn << " " << mid << " " << mx << endl;
        //for(int x : id) cout << x << " "; cout << endl;
        if(id.size() >= mid) {
            int time = 0;
            for(i = 0; i < mid; i++)
                time += a[id[i]][0];
            if(time <= k) {
                ans.resize(mid);
                m = mid;
                ok = true;
                for(i = 0; i < mid; i++) ans[i] = a[id[i]][2] + 1;
            }
        }
        if(ok)
            mn = mid;
        else
            mx = mid - 1;
    }
    cout << mn << endl;
    cout << m << endl;
    for(int id : ans) cout << id << " "; cout << endl;
    return 0;
}
