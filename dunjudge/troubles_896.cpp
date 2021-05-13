#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct CHT {
    struct Line {
        int slope, c; //slope, yIntercept
        Line(int slope, int c) : slope(slope), c(c) {}
        int val(int xCoordinate) { return slope * xCoordinate + c; }  //y coordinate
        int intersect(Line other) {  //ceiling of x coordinate of intersection
            return (other.c - c + slope - other.slope - 1) / (slope - other.slope);
        }
    };
    //Similar to monotonic queue
    deque<pair<Line, int>> dq;   //used to maintain the CHT
    void add(int slope, int yIntersect) { //add new line
        Line newLine(slope, yIntersect);
        while(dq.size() > 1 && dq.back().second >= dq.back().first.intersect(newLine)) // <= if max is optimal
            dq.pop_back();  //pop redundant(not optimal) lines
        if(dq.empty())
            dq.push_back(make_pair(newLine, 0)); //set 0 to -inf if -ve
        else
            dq.push_back(make_pair(newLine, dq.back().first.intersect(newLine)));
    }
    int qry(int xCoordinate) { //only if queries are monotonic - O(1) on average
        while(dq.size() > 1) {
            if(dq[1].second <= xCoordinate) dq.pop_front(); //finding optimal range for xCoord
            else break;
        }
        return dq[0].first.val(xCoordinate);
    }
    int query(int xCoordinate) { //works when queries are not monotonic by using binsearch
        //doing it in reverse as u can use lowerbound directly then (otherwise ull have to do --)
        auto ans = *lower_bound(dq.rbegin(), dq.rend(),
                                make_pair(Line(0, 0), xCoordinate),
                                [&] (const pair<Line, int> &a, const pair<Line, int> &b) {
                                    return a.second > b.second;  //custom comparator for the pair
                                });
        return ans.first.val(xCoordinate);
    }
};


const int N = 3002;
const int inf = 1e18;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<array<int, 2>> a(n + 1);
    vector<int> dp(n + 1, inf);
    for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    sort(all(a));
    int mx = a[1][1];
    CHT cht;
    dp[1] = a[1][0] * a[1][1];
    cht.add(a[1][1], 0);
    for(int i = 2; i <= n; i++) {
        mx = max(mx, a[i][1]);
        cht.add(a[i][1], dp[i - 1]);
        dp[i] = cht.qry(a[i][0]);
        //dp[i] = min(dp[i], mx * a[i][0]);
    }
    //for(int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];
    cout << dp[n] << '\n';
    return 0;
}
