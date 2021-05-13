#include <bits/stdc++.h>
//#include "ricehub.h"
using namespace std;

int besthub(int N, int L, int A[], long long B) {
    int answer = 0, low = 0, high = N;
    long long pref[N + 1];
    pref[0] = 0;
    for(int i = 1; i <= N; i++) pref[i] = pref[i - 1] + A[i - 1];
    while(low < high) {
        int mid = (low + high + 1) / 2;
        bool possible = false;
        for(int i = 0; i < N; i++) {
            int start = i, end = i + mid;
            if(end > N) break;
            int hub = (start + 1 + end) / 2;
            long long cost = abs((pref[hub] - pref[start]) - (long long) (hub - start) * A[hub - 1]);
            cost += abs((pref[end] - pref[hub]) - (long long) (end - hub) * A[hub - 1]);
            if(cost <= B) {
                possible = true;
                break;
            }
        }
        if(possible) {
            answer = max(answer, mid);
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("sample.in", "r", stdin);
    int n, l, b;
    cin >> n >> l >> b;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int answer = besthub(n, l, a, b);
    cout << answer << '\n';
    return 0;
}
