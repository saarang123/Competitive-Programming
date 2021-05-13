#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
int n;
int mat[3][200005];

bool dp(int i, int j)
{
    //cout << i << " " << j << "\n";
    if(i==2 && j==n+1)
        return true;
    if(i>2 || j>n)
        return false;

    if(mat[i][j] == 1 || mat[i][j] == 2)
    {
        //cout << mat[i][j] << " next\n";
        return dp(i, j+1);
    }

    if(i==1)
    {
        if(mat[2][j]==1 || mat[2][j]==2)
            return false;
        return dp(2, j+1);
    }
    if(i==2)
    {
        if(mat[1][j]==1 || mat[1][j]==2)
            return false;
        return dp(1, j+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k;
    cin >> t;
    string s1,s2;
    while(t--)
    {
        cin >> n;
        cin >> s1 >> s2;
        for(i=1; i<=n; i++)
            mat[1][i] = s1[i-1]-'0';
        for(i=1; i<=n; i++)
            mat[2][i] = s2[i-1]-'0';
        mat[1][0] = 1;
        /*
        for(i=1; i<=n; i++)
            cout << mat[1][i] << " ";
        cout << "\n";
        for(i=1; i<=n; i++)
            cout << mat[2][i] << " ";
        cout << "\n";
        */
        if(dp(1,0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
