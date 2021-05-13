#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;


const int N = 2e5+5;
int g[N], r[N]={0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n)
    {
        cin >> g[i];
        r[g[i]] = i;
    }
    vi both, fr, ba;
    RE(i,n)
    {
        if(r[i]==0 && g[i]==0)
        {
            both.pb(i);
        }
        else if(r[i]==0)
        {
            fr.pb(i);
        }
        else if(g[i]==0)
        {
            ba.pb(i);
        }
    }

    i=0;
    while(i<both.size() && i<fr.size())
    {
        g[both[i]] = fr[i];;
        r[fr[i]] = both[i];
        fr.pb(both[i]);
        i++;
    }
    if(i>=both.size())
    {
        j=0;
        while(j<ba.size() && i<fr.size())
        {
            g[ba[j]] = fr[i];
            r[fr[i]] = ba[j];
            i++;
            j++;
        }
    }
    else
    {
        int l = both.size();
        REP(i,0,both.size()-2)
        {
            g[both[i]] = both[i+1];
        }
        g[both[l-1]] = both[0];
        REB(i,both.size()-1,1)
        {
            r[both[i]] = both[i-1];
        }
        r[both[0]] = both[l-1];
    }


    RE(i,n)
    {
        cout << g[i] << " ";
    }
    cout << "\n";
    /*
    RE(i,n)
    {
        cout << r[i] << " ";
    }
    cout << "\n";
    */
    return 0;
}
