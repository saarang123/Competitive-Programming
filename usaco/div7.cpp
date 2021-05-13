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
    //ifstream fin("div7.in");
    //ofstream fout("div7.out");
    int n,i,j;
    cin >> n;
    int cur=0, pres;
    int first[7], last[7];
    for(i=0; i<7; i++)
    {
        first[i]=10000005;
        last[i] = 0;
    }
    first[0]=0;
    for(i=1; i<=n; i++)
    {
        cin >> pres;
        cur+=pres;
        cur = cur%7;
        first[cur] = min(first[cur], i);
        last[cur] = i;
    }
    int ans = 0;
    for(i=0; i<7;i++)
    {
        if(first[i]<=n)
            ans = max(ans, last[i]-first[i]);
    }
    cout << ans << "\n";
    return 0;
}
