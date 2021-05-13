#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
typedef long long ll;
int ans[1003][1003] = {1},n,m;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k,c;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<pair<int, int> > grid(n*m);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin >> k;
                grid[k-1]=(mp(i,j));
            }
        }
        for(i=0; i<n*m; i++)
        {
            pair<int, int> p = grid[i];
            clean(p.f, p.s);
            ans[p.f][p.s] = 1;

        }
        for(k=0; k<n; k++)
            {
                for(j=0; j<m; j++)
                {
                    cout << ans[k][j];
                }
                cout << "\n";
            }
            cout << "\n";

    }
    return 0;
}
