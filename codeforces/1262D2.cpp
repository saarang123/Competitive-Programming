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

const int N = 2e5+3;
int arr[N];
bool cmp(pii a, pii b)
{
    if(a.f!=b.f) return a.f>b.f;
    return a.ss<b.ss;
}

vpii a;
vpii req;
vpii ord;
map<pii, int> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,pos,m;
    cin >> n;
    RE(i,n)
    {
        cin >> j;
        arr[i] = j;
        a.pb(mp(j,i));
    }
    sort(all(a),cmp);
    cin >> m;
    RE(i,m)
    {
        cin >> k >> pos;
        req.pb(mp(k,pos));
        ord.pb(mp(k,pos));
    }
    sort(all(req));


    ordered_set oof;
    i = 0;
    REP(pq,0,m-1)
    {
        k = req[pq].f, pos = req[pq].ss;
        while(oof.size()<k)
        {
            oof.insert(a[i++].ss);
        }
        ans[req[pq]] = arr[*oof.find_by_order(pos-1)];
    }

    REP(i,0,m-1)
    {
        cout << ans[ord[i]] << "\n";
    }

    return 0;
}
