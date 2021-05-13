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

#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> t;
    while(t--)
    {
        cin >> k;
        string s;
        cin >> s;
        int h;
        REP(i,0,65)
        {
            if(k & (1LL<<i))
            {
                h = i;
                break;
            }
        }
        bool side;
        int p1 = k + (1LL<<h), p2 = k - (1LL<<h);
        if(p1 & (1LL<<(h+1))) side = 1;
        else side = 0;
        REP(i,0,s.size()-1)
        {
            //cout << k << " " << h << " " << side << "\n";
            if(s[i]=='U')
            {
                if(k==(n+1LL)/2)
                    continue;
                if(side)
                    k = k + (1LL<<h);
                else
                    k = k - (1LL<<h);
                h++;
            }
            else if(s[i]=='R')
            {
                if(k%2) continue;
                h--;
                k = k + (1LL<<h);
            }
            else
            {
                if(k%2) continue;
                h--;
                k = k - (1LL<<h);
            }
            p1 = k + (1LL<<h), p2 = k - (1LL<<h);
            if(p1 & (1LL<<(h+1))) side = 1;
            else side = 0;
        }
        cout << k << "\n";
    }
    return 0;
}
