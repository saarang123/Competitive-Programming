#include<bits/stdc++.h>
typedef long long ll;

const int N = 2e5+2;
ll pref[N], a[N];
std::pair<ll, ll> mx[N];
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,k;
    std::cin >> n >> k;
    for(int i=1; i<=n; i++) std::cin >> a[i];
    pref[0] = 0;
    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + a[i];
    for(int i=n-k+1; i; i--)
    {
        if(mx[i+1].first > pref[i+k-1]-pref[i-1]) mx[i] = mx[i+1];
        else mx[i] = std::make_pair(pref[i+k-1]-pref[i-1], i);
    }
    //for(int i=1; i<=n; i++) std::cout << mx[i].first << " " << mx[i].second << "\n";
    ll ans = 0;
    std::pair<int, int> p;
    for(int i=n-k+1; i; i--)
    {
        if(i+2*k-1>n) continue;
        //std::cout << i << '\n';
        if(pref[i+k-1]-pref[i-1]+mx[i+k].first >= ans)
        {
            ans = pref[i+k-1]-pref[i-1]+mx[i+k].first;
            p = std::make_pair(i, mx[i+k].second);
        }
    }
    //std::cout << ans << '\n';
    std::cout << p.first << " " << p.second << '\n';
    return 0;
}
