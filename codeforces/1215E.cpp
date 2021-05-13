#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 20;
int a[N], cnt[N][N],dp[1<<N];
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> k;
        k--;
        for(j=0; j<20; j++)
        {
            if(k!=j)
                cnt[j][k] += a[j];
        }
        a[k]++;
    }

    for(i=0; i<(1<<20); i++) dp[i] = 1e16;
    dp[0] = 0;
    for(int mask=0; mask<(1<<20); mask++)
    {
        for(i=0; i<20; i++)
        {
            if(mask & (1<<i)) continue;
            int tmp = dp[mask];
            for(j=0; j<20; j++)
            {
                if(mask & (1<<j)) tmp += cnt[i][j];
            }
            dp[mask | (1<<i)] = min(dp[mask | (1<<i)], tmp);
        }
    }
    cout << dp[(1<<20)-1] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
