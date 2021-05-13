#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> a(n), bit(65);
    for(int &x : a) {
    	cin >> x;
    	bit[__builtin_ctzll(x)]++;
    }
    int mx = 0;
    for(int i = 0; i < 65; i++)
    	if(bit[i] > bit[mx])
    		mx = i;
    cout << n - bit[mx] << '\n';
    for(int x : a)
    	if(__builtin_ctzll(x) != mx)
    		cout << x << ' ';
    cout << '\n';
    return 0;
}