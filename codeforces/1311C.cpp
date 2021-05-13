#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
//#define int long long
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

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2e5+5;

void solve_case()
{
    int n,i,j,t,k,m;
    string s;
    cin >> n >> m;
    cin >> s;
    int p[m+2]={0}, ans[30]={0}, cnt[n+2][30]={0};
    RE(i,m) cin >> p[i];
    p[m+1] = n;
    RE(i,n)
    {
        REP(j,0,25)
        {
            cnt[i][j] = cnt[i-1][j] + ((s[i-1]-'a')==j);
        }
    }
    RE(i,m+1)
    {
        REP(j,0,25)
        {
            ans[j] += cnt[p[i]][j];
        }
    }
    /*
    RE(i,n)
    {
        REP(j,0,25) cout << cnt[i][j] << " ";
        cout << "\n";
    }
    */
    RE(i,26) cout << ans[i-1] << " "; cout << "\n";

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
