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
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n+5];
        REP(i,0,n-1) cin >> a[i];
        vi v;
        REP(i,0,n-2)
        {
            if(a[i]!=-1 && a[i+1]==-1) v.pb(a[i]);
        }
        REP(i,1,n-1)
        {
            if(a[i]!=-1 && a[i-1]==-1) v.pb(a[i]);
        }
        if(v.empty())
        {
            cout << 0 << " " << 69420 << "\n";
            continue;
        }
        sort(all(v));
        k = (v.back() + v.front()) / 2;
        REP(i,0,n-1) if(a[i]==-1) a[i] = k;
        int m = 0;
        REP(i,0,n-2)
        {
            m = max(m, abs(a[i+1]-a[i]));
        }
        cout << m << " " << k << "\n";

    }
    return 0;
}
