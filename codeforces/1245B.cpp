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
    int n,i,j,t,a,b,c;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> a >> b >> c;
        cin >> s;
        int ans = 0;
        string sol = "";
        for(i=0; i<n; i++)
        {
            if(s[i]=='R' && b>0)
            {
                b--;
                ans++;
                sol+="P";
            }
            else if(s[i]=='P' && c>0)
            {
                c--;
                ans++;
                sol+="S";
            }
            else if(s[i]=='S' && a>0)
            {
                a--;
                ans++;
                sol+="R";
            }
            else
                sol+=" ";
        }
        int tot;
        if(n%2==0)
            tot = n/2;
        else
            tot = n/2+1;
        if(ans>=tot)
        {
            cout << "YES\n";
            for(i=0; i<n; i++)
            {
                if(sol[i]==' ')
                {
                    if(a>0)
                    {
                        cout << "R";
                        a--;
                    }
                    else if(b>0)
                    {
                        cout << "P";
                        b--;
                    }
                    else if(c>0)
                    {
                        cout << "S";
                        c--;
                    }
                }
                else
                    cout << sol[i];
            }
            cout << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}
