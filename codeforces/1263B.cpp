#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int check(string s1, string s2)
{
    int f = -1;
    for(int i=0; i<4; i++)
    {
        if(s1[i]!=s2[i])
            f = i;
    }
    return f;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {


        cin >> n;
        string s[n];
        int pick[10]={0};
        int ans = 0;
        for(i=0; i<n; i++)
            cin >> s[i];
        for(i=0; i<n; i++)
            pick[s[i][0]-'0']=1;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                int a = check(s[i], s[j]);
                if(a==-1)
                {
                    k=0;
                    while(pick[k]==1)
                        k++;
                    s[i][0] = '0'+k;
                    pick[k] = 1;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
        for(i=0; i<n; i++)
            cout << s[i] << "\n";
    }
    return 0;
}
