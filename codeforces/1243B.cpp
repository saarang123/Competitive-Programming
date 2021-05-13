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
    string s1,s2;
    cin >> t;
    while(t--)
    {
        cin >> n >> s1 >> s2;
        int cnt = 0;
        vector<int> v;
        for(i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                v.pb(i);
            }
        }
        if(cnt==2 && s1[v[0]]==s1[v[1]] && s2[v[1]]==s2[v[0]])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
