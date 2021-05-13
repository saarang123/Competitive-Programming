#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> vec;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (a[i]>a[j]) {
                vec.push_back({abs(a[i]-a[j]),{i,j}});
            } else {
                vec.push_back({abs(a[j]-a[i]),{j,i}});
            }
        }
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for (pair<int,pair<int,int>> p : vec) {
        cout << "? " << p.second.first << ' ' << p.second.second << endl;
        string res;
        cin >> res;
        if (res == "Yes") {
            cout << "! " << p.second.first << ' ' << p.second.second << endl;
            exit(0);
        }
    }
    cout << "! 0 0" << endl;
}
/*

*/
