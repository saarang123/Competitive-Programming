#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j;
    string s,t;
    cin >> n;
    int rep[26];
    while(n--)
    {
        cin >> s >> t;
        bool ans = 0;
        memset(rep, 0, sizeof rep);
        if(s.compare(t)==0)
            ans = 1;
        else if(s.size()!=t.size())
            ans = 0;
        else
        {
            bool all = 1;
            for(i=0; i<t.size(); i++)
            {
                all = 0;
                for(j=0; j<s.size(); j++)
                {
                    if(t[i] == s[j])
                    { all = 1; break; }
                }
            }
            if(all==0)
                ans = 0;
            else
            {
                for(i=0; i<t.size(); i++)
                {
                    rep[t[i]-'a'] += 1;
                    if(rep[t[i]-'a'] > 1)
                        ans = 1;
                }
            }
        }
        if(ans)
            cout << "YES" <<"\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
