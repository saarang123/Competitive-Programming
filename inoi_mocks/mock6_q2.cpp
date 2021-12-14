#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXM = 2003 + 3;
const int MXN = 10000;
bool dp[MXN][MXM];
ll pw[MXN], ten[MXN];
int p, m, x;

string foo(int i, int r) {
	if(i == 0 && r == 0)
		return "";
	if(i == 0 && r) {
		//assert(false);
		return "wtf";
	}
	for(int k = 0; k < 26; k++) {
		ll next = r - pw[i - 1] * (k + 1);
		next %= m;
		next = (next + m) % m;
		if(dp[i - 1][next])
			return char('a' + k) + foo(i - 1, next);
	}
	//assert(false);
	return "wtf";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> p >> m >> x;
    if(x <= 26) 
    	return cout << char('a' + x - 1) << '\n', 0;
    pw[0] = ten[0] = 1;
    for(int i = 1; i <= m; i++) {
    	pw[i] = pw[i - 1] * p;
    	pw[i] %= m;
    	ten[i] = ten[i - 1] * 10;
    	ten[i] %= m;
    }
    dp[0][0] = true;
    for(int i = 1; i < MXN; i++) {
    	int place = i - 1;
    	for(int j = 0; j < m; j++) {
    		for(ll k = 0; k < 26; k++) {
    			if(dp[i - 1][j]) {
    				ll next = j + pw[place] * (k + 1);
    				next %= m;
    				dp[i][next] = true;
    			}
    		}		
    	}
    	if(dp[i][x]) {
    		//cout << "I am here!";
    		string out = foo(i, x);
    		reverse(out.begin(), out.end());
    		cout << out << '\n';
    		exit(0);
    	}
    }
    assert(false);
    return 0;
}