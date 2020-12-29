#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5002;
int s[N], c[N], dp[N][N], pref[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> s[i], pref[i] = pref[i - 1] + s[i];
    
    return 0;
}
