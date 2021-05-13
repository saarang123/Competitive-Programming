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
typedef pair<int, int> pii;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a[100005];
        pii ev[100005][3], od[100005][3];
        for(i=1;  i<=n; i++)
        {
            cin >> a[i];
        }
        ev[n+1][1] = mp(0,1000000);
        ev[n+1][2] = mp(0,1000000);

        for(i=n; i>0; i--)
        {
            if(a[i]%2!=0)
            {
                if(ev[i+1][1].f>ev[i+1][2].f)
                    ev[i][1] = ev[i+1][1];
                else if(ev[i+1][1].f==ev[i+1][2].f)
                    ev[i][1] = ev[i+1][1].s < ev[i+1][2].s ? ev[i+1][1]:ev[i+1][2];
                else
                    ev[i][1] = ev[i+1][2];

                if(ev[i+1][1].f>ev[i+1][2].f)
                    ev[i][2] = ev[i+1][1];
                else if(ev[i+1][1].f==ev[i+1][2].f)
                    ev[i][2] = ev[i+1][1].s < ev[i+1][2].s ? ev[i+1][1]:ev[i+1][2];
                else
                    ev[i][2] = ev[i+1][2];
                continue;
            }

            int ans = 0;

            if(ev[i+1][1].s-i > k)
                ans = max(ans, ev[i+1][1].f+a[i]);
            else
                ans = max(ans, ev[i+1][1].f);
            if(ev[i+1][2].s-i > k)
                ans = max(ans, ev[i+1][2].f +a[i]);
            else
                ans = max(ans, ev[i+1][2].f);

            if(ans==ev[i+1][2].f+a[i] || ans==ev[i+1][1].f+a[i])
                ev[i][1] = mp(ans, i);
            else if(ans==ev[i+1][2].f)
                ev[i][1] = mp(ans, ev[i+1][2].s);
            else
                ev[i][1] = mp(ans, ev[i+1][1].s);

            if(ev[i+1][1].f>ev[i+1][2].f)
                ev[i][2] = ev[i+1][1];
            else if(ev[i+1][1].f==ev[i+1][2].f)
                ev[i][2] = ev[i+1][1].s > ev[i+1][2].s ? ev[i+1][1]:ev[i+1][2];
            else
                ev[i][2] = ev[i+1][2];
        }

        od[n+1][1] = mp(0,1000000);
        od[n+1][2] = mp(0,1000000);

        for(i=n; i>0; i--)
        {
            if(a[i]%2==0)
            {
                if(od[i+1][1].f>od[i+1][2].f)
                    od[i][1] = od[i+1][1];
                else if(od[i+1][1].f==od[i+1][2].f)
                    od[i][1] = od[i+1][1].s < od[i+1][2].s ? od[i+1][1]:od[i+1][2];
                else
                    od[i][1] = od[i+1][2];

                if(od[i+1][1].f>od[i+1][2].f)
                    od[i][2] = od[i+1][1];
                else if(od[i+1][1].f==od[i+1][2].f)
                    od[i][2] = od[i+1][1].s < od[i+1][2].s ? od[i+1][1]:od[i+1][2];
                else
                    od[i][2] = od[i+1][2];
                continue;
            }

            int ans = 0;

            if(od[i+1][1].s-i > k)
                ans = max(ans, od[i+1][1].f+a[i]);
            else
                ans = max(ans, od[i+1][1].f);
            if(od[i+1][2].s-i > k)
                ans = max(ans, od[i+1][2].f +a[i]);
            else
                ans = max(ans, od[i+1][2].f);

            if(ans==od[i+1][2].f+a[i] || ans==od[i+1][1].f+a[i])
                od[i][1] = mp(ans, i);
            else if(ans==od[i+1][2].f)
                od[i][1] = mp(ans, od[i+1][2].s);
            else
                od[i][1] = mp(ans, od[i+1][1].s);

            if(od[i+1][1].f>od[i+1][2].f)
                od[i][2] = od[i+1][1];
            else if(od[i+1][1].f==od[i+1][2].f)
                od[i][2] = od[i+1][1].s > od[i+1][2].s ? od[i+1][1]:od[i+1][2];
            else
                od[i][2] = od[i+1][2];
        }

        /*
        for(i=1; i<=n; i++)
        {
            cout << "(" << ev[i][1].f << " " << ev[i][1].s << ")" << " " << "(" << ev[i][2].f << " " << ev[i][2].s << ")" << "\n";
        }
        for(i=1; i<=n; i++)
        {
            cout << "(" << od[i][1].f << " " << od[i][1].s << ")" << " " << "(" << od[i][2].f << " " << od[i][2].s << ")" << "\n";
        }
        */

        int sum = 0;
        sum += od[1][1].f>od[1][2].f ? od[1][1].f:od[1][2].f;
        sum += ev[1][1].f>ev[1][2].f ? ev[1][1].f:ev[1][2].f;
        cout << sum << "\n";

    }
    return 0;
}
