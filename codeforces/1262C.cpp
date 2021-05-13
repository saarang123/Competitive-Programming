#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

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
        string s;
        cin >> s;
        int a[n], b[n];
        for(i=0; i<n; i++)
        {
            if(s[i] == '(')
                a[i] = 1;
            else
                a[i] = -1;
        }
        j=0;
        for(i=1; i<k; i++)
        {
            b[j] = 1;
            b[j+1] = -1;
            j+=2;
        }
        //cout << j << "\n";
        int l = n-j;
        for(i=j; i<n-l/2; i++)
            b[i] = 1;
        for(;i<n; i++)
            b[i] = -1;
        /*
        for(i=0; i<n; i++)
            cout << b[i] << " ";
        cout << "\n";
        */
        vector<pair<int, int> > ans;
        for(i=0; i<n; i++)
        {
            if(a[i]!=b[i])
                ans.pb(mp(i+1,i+1));
        }
        cout << ans.size() << "\n";
        for(i=0; i<ans.size(); i++)
        {
            cout << ans[i].f << " " << ans[i].s << "\n";
        }

    }

    return 0;
}
