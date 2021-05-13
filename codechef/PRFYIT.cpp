#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;


int count(string a, string b, int p)
{
    int m = a.length();
    int n = b.length();
    if(p>=m) return 0;
    int lookup[m + 1][n + 1] = { { 0 } };

    for (int i = 0; i <= n; ++i)
        lookup[0][i] = 0;

    for (int i = 0; i <= m; ++i)
        lookup[i][0] = 1;

    for (int i = p; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] +
                               lookup[i - 1][j];

            else
                lookup[i][j] = lookup[i - 1][j];
        }
    }

    return lookup[m][n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        n = s.size();
        int a[n] = {0},sum=0;
        for(i=0; i<n; i++)
        {
            if(s[i]=='0')
                a[i] = count(s, "101", i+1);
            else
                a[i] = count(s,"010",i+1);
            sum+=a[i];
        }
        cout << sum << "\n";

    }
    return 0;
}
