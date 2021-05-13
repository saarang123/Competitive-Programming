#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1000000000000000000;
const ll MOD = 1000000007;
const int MAXN = 100001;
int n;
int index(int i){
    if(i > n + 1)i = n + 1;
    return i;
}

int main(){
    cin >> n;
    pair<int,ll> all[n];
    for(int i = 0; i < n; i++) cin >> all[i].second;
    for(int i = 0; i < n; i++) cin >> all[i].first;
    for(int i = 0; i < n; i++) all[i].first++;
    ll dp[n + 2];
    for(int i = 0; i < n + 2; i++) dp[i] = INF;
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            dp[index(j + all[i].first)] = min(dp[index(j + all[i].first)],dp[j] + all[i].second);
        }
    }
    cout << min(dp[n+1],dp[n]) << endl;

    return 0;
}


