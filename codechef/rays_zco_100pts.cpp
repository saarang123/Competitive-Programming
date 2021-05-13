#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
int n,m;
vector<set<pair<int, int> > > grid(1000005);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,xi,yi,w,b;
    cin >> n >> m >> w >> b;
    for(i=0; i<w; i++)
    {
        cin >> xi >> yi;
        xi--;
        grid[xi].insert(mp(yi, 1));
    }
    for(i=0; i<b; i++)
    {
        cin >> xi >> yi;
        xi--;
        grid[xi].insert(mp(yi, 0));
    }
    ll ans = 0;
    for(i=0; i<n; i++)
    {
        set<pair<int, int> > ::iterator j;
        cout << i << ": ";
        for(j = grid[i].begin(); j!=grid[i].end(); j++)
        {
            pair<int, int> p = *j;
            cout << p.f << " " << p.s << ", ";
        }
        cout <<"\n";
    }

    for(i=0; i<n; i++)
    {
        int no=-1, cur=-1 , len = 0,p,col;
        set<pair<int, int> > ::iterator itr;
        for(itr = grid[i].begin(); itr!=grid[i].end(); itr++)
        {
            p = (*itr).f, col = (*itr).s;
            if(col==1)
            {
                if(no==0)
                {
                    cur = p;
                    no++;
                }
                else if(no ==1)
                {
                    ans += (cur-len)*(cur-len+1)/2 - (p-cur)*(p-cur+1)/2;

                }
            }
            else
            {
                ans+=(p-cur-len)*(p-cur-len+1)/2 - (cur+1)*(cur+2)/2;
                cout << len << " " << p << " " << ans << " black\n";
                len = p+1;
            }
        }
        ans+=(n-len-cur)*(n-len-cur+1)/2;
        cout << len << " " << p << " " << ans << " end\n";
    }
    cout << ans << "\n";
    return 0;
}
