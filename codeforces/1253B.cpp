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
    int n,i,j,t,k=0;
    cin >> n;
    int a[n+1];
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    map<int, int> s;
    vector<int> ans;
    set<int> pres;
    j=1;
    for(i=1; i<=n; i++)
    {
        if(s.find(abs(a[i]))!=s.end())
        {
            s.erase(abs(a[i]));
            k++;
        }
        else
        {
            if(a[i]<0)
            {
                j=0;
                break;
            }
            if(pres.count(a[i]))
            {
                j=0;
                break;
            }
            pres.insert(a[i]);
            s[a[i]] = 1;
            k++;
        }
        if(s.empty())
        {
            pres.clear();
            ans.pb(k);
            k=0;
        }
    }
    if(!s.empty())
        j=0;
    if(j==0)
        cout << -1 << "\n";
    else
    {
        cout << ans.size() << "\n";
        for(i=0; i<ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}
