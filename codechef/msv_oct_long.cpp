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
    int t,n,i,j;
    cin >> t;
    while(t--)
    {
        vector<set<int> > v(1000003);
        v.clear();
        cin >> n;
        int a[100005], ans[n+1];
        for(i=1; i<=n; i++)
        {
            cin >> a[i];
            ans[i]=0;
            v[a[i]].insert(i);
        }
        int flag = 1;
        for(i=1; i<=n-1; i++)
            if(a[i]!=a[i+1])
                flag = 0;
        if(flag)
            cout << n-1 << "\n";
        else
        {
            int pres;
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=sqrt(a[i]); j++)
                {
                    if(a[i]%j==0)
                    {
                        for(auto x = v[j].begin(); x!=v[j].end(); x++)
                        {
                            if(*x>i)
                            {    ans[*x]++;
                                //cout << j << " " << a[i] << " " << *x << "\n";
                                }
                        }
                        if(v[a[i]/j]!=v[j])
                            for(auto x = v[a[i]/j].begin(); x!=v[a[i]/j].end(); x++)
                            {
                                if(*x>i)
                                {    ans[*x]++;
                                    //cout << a[i]/j << " " << a[i] << " " << *x << "\n";
                                    }
                            }
                    }
                }
            }
            int sol = -1;
            for(i=1; i<=n; i++)
            {
                sol = max(sol, ans[i]);
                //cout << ans[i] << " ";
            }
            cout << sol << "\n";
        }
    }
    return 0;
}
