#include <bits/stdc++.h>
using namespace std;
const int MXN = 803;
int a[MXN][MXN], p[MXN][MXN];
int n, k, need;

bool check(int x) {
    memset(p, 0, sizeof p);
    //cout << "x: " << x << endl;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            p[i][j] = (a[i][j] > x) + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            //cout << p[i][j] << " \n"[j == n];
        }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(0 <= i - k && 0 <= j - k) {
                int sum = p[i][j] - p[i - k][j] - p[i][j - k] + p[i - k][j - k];
                if(sum < need)
                    return true;
            }
        }
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k;
    need = (k * k) / 2 + 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    int mn = 0, mx = 1e9 + 3;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        //cout << mn << ' ' << mid << ' ' << mx << endl;
        if(check(mid))
            mx = mid;
        else
            mn = mid + 1;
    }
    cout << mn << '\n';
    return 0;
}