#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e15;
const int N = 1502;

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


signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    CHT cht;
    dp[1] = a[1] * n;
    cht.add(n, 0); //querying all n at one time
    int mx = a[1];
    for(int i = 2; i <= n; i++) {
        mx = max(mx, a[i]);
        cht.add(n - i + 1, dp[i - 1]);
        dp[i] = cht.qry(mx);
        //we can qry for mx cuz the x coordinate has to be atleast mx (all under same time mx)
    }
    cout << dp[n] << '\n';
    return 0;
}
