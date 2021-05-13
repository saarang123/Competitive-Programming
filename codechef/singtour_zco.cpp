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

int win(pair<int, int> p1, pair<int, int> p2)
{
    if((p1.f<p2.f && p1.s>=p2.s) || (p1.f<=p2.f && p1.s>p2.s))
        return 1;
    else if(p2.f<p1.f && p2.s>p1.s)
        return 0;
    else
        return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector< pair<int, int> > l, r;
        int a[n] = {0};

        for(i=0; i<n; i++)
        {
            cin >> j >> k;
            l.pb(mp(j,i));
            r.pb(mp(k,i));
        }

        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        for(i=0; i<n; i++)
        {
            a[l[i].s] += n - i - 1;   //points are added for all L that are > L[i]
            a[r[i].s] += i;           //points added for all R < R[i]
        }

        /*
        1 point is added for all L > L[i]
        1 point added for all R < R[i]
        therefore, if (L,R) wins again another (l,r), 2 points are added for L<l and R>r.
        In all other draws, atleast one L or R is greater than r or l.
        If its a loss, L>l and R<r so 0 points.
        By this way, all necessary points are given.
        This solution works as the draw points is half the win points.
        */

        for(i=0; i<n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
