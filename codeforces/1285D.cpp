#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
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

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

//-------------------------------------------------Template Ends------------------------------------------------------/

vi a;

ll solve(vi a, int i)
{
    if(a.size()==0 || i<0) return 0;
    vi l,r;
    for(int j=0; j<a.size(); j++)
    {
        //Splitting elements into 2 lists if ith bit is on or off
        if(a[j] & (1<<i))
            l.pb(a[j]);
        else r.pb(a[j]);
    }
    if(l.size()==0) return solve(r,i-1);
    //If ith is only off, we can make ith bit in X also off so we dont have to add (1<<i)
    if(r.size()==0) return solve(l,i-1);
    //if ith bit only on, we can make ith bit in X also on so XOR wont give (1<<i)
    return (1<<i) + min(solve(l,i-1), solve(r,i-1));
    //If it has both on and off bits in the array, whether ith bit in X is on or off, there will be (1<<i)
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n) { cin >> j; a.pb(j); }
    cout << solve(a,30) << "\n";
    return 0;
}
