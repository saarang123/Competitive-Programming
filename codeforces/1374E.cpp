#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define int long long
#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define trav(i,a) for(auto i: a)
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

void solve_case()
{
    int n,i,j,k,m;
    cin >> n >> m;
    vi cnt[3];
    RE(i,n)
    {
        int w,u,v;
        cin >> w >> u >> v;
        if(u==1 && v==1)
        {
            cnt[0].pb(w);
        }
        else if(u==1)
            cnt[1].pb(w);
        else if(v==1) cnt[2].pb(w);
    }
    FOR(i,3) sort(all(cnt[i]));
    int ans = 0, t[2] = {0,0};
    i=0,j=0,k=0;
    int na = cnt[0].size(), nb = cnt[1].size(), nc = cnt[2].size();
    while(t[0]<m || t[1]<m)
    {
        int tmp = 1e10;
        if(k<na) tmp = cnt[0][k];
        if(t[0]<m && t[0]<m)
        {
            int cur = -1;
            if(i<nb && j<nc)
            {
                cur = cnt[1][i] + cnt[2][j];
                if(cur<=tmp)
                {
                    i++; j++;
                    ans += cur;
                    t[0]++; t[1]++;
                }
                else
                {
                    ans += tmp;
                    k++;
                    t[0]++; t[1]++;
                }
            }
            else
            {
                ans += tmp;
                k++;
                t[0]++; t[1]++;
            }
            continue;
        }
    }
    if(ans>=1e10) cout << -1 << "\n";
    else cout << ans << '\n';
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
