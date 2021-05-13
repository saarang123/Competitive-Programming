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
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
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


//cmp comparison ensures the subsequence is lexicographically least.
bool cmp(pii a, pii b)
{
    if(a.f!=b.f) return a.f < b.f;
    return a.ss>b.ss;
}

const int N=105;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,pos,k,m;
    cin >> n;
    vpii a;
    RE(i,n)
    {
        cin >> j;
        a.pb(mp(j,i));
    }
    sort(a.begin(), a.end(), cmp);
    cin >> m;
    while(m--)
    {
        cin >> k >> pos;
        vpii ans;
        REP(i,n-k,n-1)
        {
            ans.pb(mp(a[i].ss, a[i].f)); //Last k elements hv largest sum.
        }
        sort(ans.begin(), ans.end());
        cout << ans[pos-1].ss << "\n";
    }
    return 0;
}
