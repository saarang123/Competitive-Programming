#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+3;
vector<int> ans, cnt(N);
vector<pair<int, int>> segs(N), tmp[N];
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> k;
    for(i=1; i<=n; i++)
    {
        cin >> segs[i].first >> segs[i].second;
        cnt[segs[i].first]++; cnt[segs[i].second+1]--;
        tmp[segs[i].first].push_back(make_pair(segs[i].second, i));
    }
    priority_queue<pair<int, int>> pq;
    for(i=1; i<N; i++)
    {
        cnt[i] += cnt[i-1];
        for(auto a: tmp[i]) pq.push(a);
        while(cnt[i]>k)
        {
            ans.push_back(pq.top().second);
            ++cnt[pq.top().first+1];
            cnt[i]--;
            pq.pop();
        }
    }
    cout << ans.size() << "\n";
    for(int u: ans) cout << u << " "; cout << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
