#include <bits/stdc++.h>
using namespace std;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j, w, b, x = 0;
        cin >> b >> w;
        if(w > b) {
            swap(w, b);
            x = 1;
        }
        if(w * 3 + 1 < b) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(i = 0; i < 2 * w; i++)
            cout << 2 << " "  << i + 1 + x << endl;
        b -= w;
        if(b > 0) {
            cout << 2 << " " << 2 * w + 1 + x << endl;
            b--;
        }
        for(i = 0; i < b && i < w; i++)
            cout << 3 << " " << 2 * (i + 1) + x << endl;
        b -= w;
        for(i = 0; i < b && i < w; i++)
            cout << 1 << " " << 2 * (i + 1) + x << endl;
    }
    return 0;
}
