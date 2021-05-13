#include <functional>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <deque>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <sstream>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

typedef long long ll;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

ll h, w, n;
ll ans[11];
std::map<std::pair<int, int>, bool> cnt;
std::map<std::pair<int, int>, bool> vis;
std::vector<std::pair<int, int>> ed;

int check(int x, int y) {
    int fix = 0;
    for(int i=x; i<x+3; i++) {
        for(int j=y; j<y+3; j++) {
            fix += cnt[std::make_pair(i,j)];
        }
    }
    return fix;
}

bool in(int x, int y)
{
    return (x>0 && y>0 && x<=h && y<=w) && (x+2<=h && y+2<=w && x+2>0 && y+2>0);
}

void solve() {
    std::cin >> h >> w >> n;
    for(int i=0; i<n; i++) {
        std::pair<int, int> a;
        std::cin >> a.first >> a.second;
        ed.push_back(a);
        cnt[a] = 1;
    }
    for(int i=0; i<n; i++) {
        std::pair<int, int> a = ed[i];
        int x = a.first, y = a.second;
        //std::cout << "point " << i << " " << x << " " << y << std::endl;
        for(int cur=x; cur>x-3; cur--) {
            for(int nxt=y; nxt>y-3; nxt--) {
                if(vis[std::make_pair(cur,nxt)]) continue;
                if(!in(cur,nxt)) continue;
                //std::cout << "3x3: " << cur << " " << nxt << " count: " << check(cur,nxt) << std::endl;
                ans[check(cur,nxt)]++;
                vis[std::make_pair(cur,nxt)] = 1;
            }
        }
    }
    ll sum = 0;
    for(int i=1; i<10; i++) sum += ans[i];
    ans[0] = (h-2)*(w-2) - sum;
    for(int i=0; i<10; i++) std::cout << ans[i] << std::endl;
}

int main () {
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}
