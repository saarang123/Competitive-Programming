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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m=0;
    cin >> n >> k;
    int p[31]={0};
    for(i=0; i<=30; i++)
    {
        if(n & (1<<i))
        {
            p[i]++;
            m++;
        }
    }
    //REP(i,0,30) cout << p[i] << " "; cout << "\n";
    if(k<m)
        return cout << "NO\n",0;
    t = k-m;

    i = 30;
    while(t && i)
    {
        while(p[i] && t)
        {
            p[i]--;
            p[i-1] += 2;
            t-=1;
        }
        i--;
    }
    int cnt = 0;
    REP(i,0,30) cnt+=p[i];
    //REP(i,0,30) cout << p[i] << " "; cout << "\n";
    if(cnt<k) return cout << "NO\n",0;
    cout << "YES\n";
    REP(i,0,30)
    {
        if(p[i]==0) continue;
        while(p[i])
        {
            cout << (1<<i) << " ";
            p[i]--;
        }
    }
    cout << "\n";
    return 0;
}
