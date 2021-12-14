#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int lim = 100'000;

const int INF = 1'000'000'001;

using vi = vector<int>;

vi dp = vi(4 * (1+lim), INF);

const int A_empty = 0;
const int A_full = 1;
const int B_empty = 2;
const int B_full = 3;

int A, B, K, L;

int getA(int s)
{
    if(s % 4 == A_empty) return 0;
    else if(s % 4 == A_full) return A;
    else return s/4;
}

int getB(int s)
{
    if(s % 4 == B_empty) return 0;
    else if(s % 4 == B_full) return B;
    else return s/4;
}

int getState(int a, int b)
{
    if(a == 0) return 4*b + A_empty;
    else if(a == A) return 4*b + A_full;
    else if(b == 0) return 4*a + B_empty;
    else return 4*a + B_full;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B >> K >> L;

    dp[getState(0, 0)] = 0;

    queue<int> tbv;
    tbv.push(getState(0, 0));

    while(!tbv.empty())
    {
        int u = tbv.front();
        tbv.pop();


        int a = getA(u);
        int b = getB(u);

        vi nxt;
        nxt.push_back(getState(A, b));
        nxt.push_back(getState(a, B));
        nxt.push_back(getState(0, b));
        nxt.push_back(getState(a, 0));

        int pourA = min(A-a, b);
        nxt.push_back(getState(a + pourA, b - pourA));

        int pourB = min(B-b, a);
        nxt.push_back(getState(a - pourB, b + pourB));

        for(int v: nxt)
        {
            if(dp[v] <= 1 + dp[u]) continue;
            dp[v] = 1 + dp[u];
            tbv.push(v);
        }
    }

    int ans = INF;

    for(int i = 0; i < 4*(1+lim); i++)
    {
        if(dp[i] <= K)
        {
            // cerr << getA(i) << ' ' << getB(i) << ' ' << dp[i] << '\n';
            ans = min(ans, abs(L - getA(i) - getB(i)));
        }
    }


    cout << ans << '\n';
}
