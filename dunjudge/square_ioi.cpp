#include <bits/stdc++.h>
#include "square.h"
using namespace std;

int findMaxSquare(int a[SIZE][SIZE], int n) {
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
    function<int(int k)> check = [&] (int k) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i + k - 1 > n || j + k - 1 > n) continue;
                if(pref[i + k - 1][j + k - 1]  - pref[i + k - 1][j - 1] - pref[i - 1][j + k - 1] + pref[i - 1][j - 1] == k * k)
                    cnt++;
            }
        }
        return cnt;
    };
    int mn = 1, mx = n;
    while(mn < mx) {
        int mid = (mn + mx + 1) >> 1;
        //cout << "binsearch: " << mn << " " << mid << " " << mx << endl;
        if(check(mid) > 0)
            mn = mid;
        else
            mx = mid - 1;
    }
    long long ans = check(mn) * mn;
    return ans;
}

/*
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
    cout << findMaxSquare(a, n) << '\n';
    return 0;
}*/
