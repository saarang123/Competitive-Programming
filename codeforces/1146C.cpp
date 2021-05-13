#include<bits/stdc++.h>
typedef long long ll;


int query(std::vector<int> q1, std::vector<int> q2)
{
    if(q1.size() == 0 || q2.size() == 0) return 0;
    std::cout << q1.size() << " " << q2.size();
    for(int u: q1) std::cout << " " << u;
    for(int u: q2) std::cout << " " << u;
    std::cout << std::endl;
    std::cout.flush();
    int res;
    std::cin >> res;
    return res;
}

void solve_case()
{
    int n,i,j,t,k,m;
    std::cin >> n;
    std::vector<int> q1,q2;
    int ans = 0;
    for(i=8; i>=0; i--)
    {
        q1.clear(); q2.clear();
        for(j=1; j<=n; j++)
        {
            if(j&(1<<i)) q1.push_back(j);
            else q2.push_back(j);
        }
        ans = std::max(ans, query(q1,q2));
    }
    std::cout << -1 << " " << ans << std::endl;
    std::cout.flush();
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
