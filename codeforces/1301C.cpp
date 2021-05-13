#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vpll ans;
        RE(i,n)
        {
            ans.pb(mp(i*(n-i+1), i));
        }
        sort(ans.rbegin(), ans.rend());
        //REP(i,0,n-1) cout << ans[i] << " ";
        //cout << "\n";
        vl lol;
        i = 0;
        while(m--)
        {
            lol.pb(ans[i++].ss);
        }
        sort(lol.begin(), lol.end());
        REP(i,0,n-1) cout << lol[i] << " ";
        cout << "\n";
        ll out = 0;
        ll prev = 0;
        REP(i,0,m-1)
        {
            out += (n-lol[i]+1)*(lol[i]-prev);
            prev = lol[i];
        }
        cout << out << "\n";
    }
    return 0;
}
