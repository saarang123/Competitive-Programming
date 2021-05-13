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
    int n,i,j, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        map<string, pair<int, int> > dict;
        string s;
        int ans=0;
        for(i=0; i<n; i++)
        {
            cin >> s >> j;
            if(j==0)
            {
                dict[s].f +=1;
            }
            else
                dict[s].s += 1;
        }
        for(auto itr=dict.begin(); itr!=dict.end(); itr++)
        {
            pair<int, int> p = itr->s;
            ans+= max(p.f, p.s);
        }
        cout << ans << "\n";
    }
    return 0;
}
