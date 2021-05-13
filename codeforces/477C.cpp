#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
int dp[N][N], a[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    //think of all possible state eliminations not just one
    //a[i] - min length to get a subsequence of t starting from index i
    //dp[i][j] = no. of substrings from till index i deleting j chars
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for(int i = 0; i < n; i++) {
    	int j = i, k;
    	for(k = 0; k < m && j < n; k++, j++) {
    		while(j < n && s[j] != t[k]) j++;
    	}
    	if(k >= m) a[i] = j - i;
    	else a[i] = -1;
    }
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j <= i; j++) {
    		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]); //take char
    		dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]); //delete char
    		if(a[i] > 0)        //take a subtring of t
    			dp[i + a[i]][j + a[i] - m] = max(dp[i + a[i]][j + a[i] - m], dp[i][j] + 1);
    	}
    }
    for(int i = 0; i <= n; i++) cout << dp[n][i] << ' '; cout << '\n';
    return 0;
}