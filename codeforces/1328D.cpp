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
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 2e5+5;
int t[N], c[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,q,k,m;
    cin >> q;
    while(q--)
    {
        cin >> n;
        RE(i,n) cin >> t[i];
        k = 0;
        bool a = (t[n]!=t[1]);
        RE(i,n-1)
        {
            if(t[i]!=t[i+1])
            {
                k++;
            }
        }
        k+=a;
        if(k==n)
        {
            if(n%2)
            {
                cout << 3 << "\n";
                RE(i,n-1)
                {
                    if(i%2)
                        cout << "1 ";
                    else cout << "2 ";
                }
                cout << "3\n";
            }
            else
            {
                RE(i,n-1)
                {
                    if(i%2)
                        cout << "1 ";
                    else cout << "2 ";
                }
                if(n%2)
                    cout << "1\n";
                else cout << "2\n";
            }
            continue;
        }
        if(k>0)
        {
            cout << "2\n";
            if(!a)
            {
                RE(i,n-1)
                {
                    if(i%2)
                        cout << "1 ";
                    else cout << "2 ";
                }
                if(n%2)
                    cout << "1\n";
                else cout << "2\n";
            }
            else
            {
                RE(i,n)
                {
                    if(i%2) c[i] = 1;
                    else c[i]= 2;
                }
                if(c[1]!=c[n])
                {
                    RE(i,n) cout << c[i] << " "; cout << "\n";
                }
                else
                {
                    j = n;
                    RE(i,n-1)
                    {
                        if(t[i]==t[i+1])
                        {
                            j = i+1;
                            break;
                        }
                    }
                    c[j] = c[j-1];
                    REP(i,j+1,n)
                    {
                        if(c[i]==1) c[i]=2;
                        else c[i]=1;
                    }
                    RE(i,n) cout << c[i] << " "; cout << "\n";
                }
            }
            continue;
        }
        if(k==0)
        {
            cout << "1\n";
            RE(i,n) cout << "1 "; cout << "\n";
        }
    }
    return 0;
}
