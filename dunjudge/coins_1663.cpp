#include <bits/stdc++.h>
//#include "coins.h"
using namespace std;

vector<int> coin_flips(vector<int> b, int c) {
    vector<int> flip(1);
    int xor = 0;
    for(int i = 0; i < 64; i++)
        xor ^= (i * b[i]);
    flip[0] = xor ^ c;
    return flip;
}

int find_coin(vector<int> b) {
    int c = 0;
    for(int i = 0; i < 64; i++)
        c ^= (i * b[i]);
    return c;
}


signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int c = 14;
    vector<int> b = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    b = coin_flips(b, c);
    cout << find_coin(b) << '\n';
    return 0;
}
