#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
vector<set<int> > graph(100005);
int n, ans = -INF;

int dp(int i, int a[])
{
    if(graph[i].empty())
    {
        ans = max(ans, 0);
        //cout << i << " " << ans << "\n";
        return a[i];
    }
    int ret = a[i];
    for(int adj: graph[i])
    {
        int pres = dp(adj,a);
        ret = min(ret, pres);
        ans = max(ans, a[i]-pres);
    }
    //cout << i << " " << ans << "\n";
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k;
    cin >> n;
    int a[n], p, boss;
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<n; i++)
    {
        cin >> p;
        p--;
        if(p<0)
        {
            boss = i;
            continue;
        }
        graph[p].insert(i);
    }
    /*
    for(i=0; i<n; i++)
    {
        //set<int, greater<int> > ::iterator itr;
        cout << i << ": ";
        for(auto itr=graph[i].begin(); itr!=graph[i].end(); itr++)
            cout << *itr << " ";
        cout << "\n";
    }
    */
    //cout << boss << "\n";
    dp(boss, a);
    cout << ans << "\n";
    return 0;
}
