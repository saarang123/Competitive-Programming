#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF 1000000000
#define s second
#define f first
#define MOD 1000000007
#define setitr set<int, greater<int> > :: iterator
typedef long long ll;

vector<int> bs(ll i, ll n)
{
    vector<int> v;
    ll m1 = 1, m2 = n-1;
    while(m1<=m2)
    {
        ll mid = (m1+m2)/2;
        //cout << m1 << " " << mid <<" "<< m2 << "\n";
        if(i>=mid)
        {
            m1 = mid+1;
            //cout <<1 << " ";
            v.pb(1);
        }
        else
        {
            m2 = mid-1;
            //cout << 0 << " ";
            v.pb(0);
        }
    }

    return v;
}

ll soln(vector<int> v, ll n)
{
    ll i=2, t, l=0, r=1;
    if(v[0]==0)
    {
        l = 0;
        r = 2;
    }
    else
    {
        l = 1;
        r = 3;
    }
    for(int k=1; k<v.size(); k++)
    {
        int el = v[k];
        if(el==0)
        {
            //l = r;
            r = l+pow(2,i);
        }
        else
        {
            l = r;
            r = l+pow(2,i);
        }
        i++;
        //cout << l << " " << r << "\n";
    }

    return l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t,n,k,m,i,j,p,id;
    cin >> t;
    while(t--)
    {
        cin >> p >> id;
        n = pow(2, p);
        vector<int> v = bs(id, n);

        /*
        for(i=0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        */

        ll ans = soln(v, n);
        cout << ans << "\n";

    }
    return 0;
}
