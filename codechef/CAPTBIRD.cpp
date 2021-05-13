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
typedef pair<int,int> pii;

int dist(pii a, pii b)
{
    return pow((a.f-b.f),2)+pow((a.s-b.s), 2);
}

double angle(pii a, pii b, pii c)
{
    int a2 = dist(b,c);
    int b2 = dist(c,a);
    int c2 = dist(a,b);
    double ret = acos((a2+b2-c2)/(2*sqrt(a2)*sqrt(b2)));
    return ret;
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
        vector<pii > cam;
        pii bird;
        for(i=0; i<n; i++)
        {
            cin >> j;
            cam.pb(mp(j,0));
        }
        cin >> j >> k;
        bird = mp(j,k);
        sort(cam.begin(), cam.end());

        double ans = 0;
        for(i=0; i<n/2; i++)
        {
            ans += angle(cam[i], cam[n-i-1], bird);

        }
        cout << setprecision(12) << ans << "\n";

    }
    return 0;
}
