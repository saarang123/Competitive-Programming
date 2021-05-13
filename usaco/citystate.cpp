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
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j, ans=0;
    fin >> n;
    string s, s2;
    map<string, string> a;
    set<string> state;
    for(i=0; i<n; i++)
    {
        fin >> s >> s2;
        string s3(1,s[0]);
        s3+=s[1];
        //cout << s3 << " " << s2 << "\n";
        a[s2+s3] = s3+s2;
        ;
    }
    for(auto itr = a.begin(); itr!=a.end(); itr++)
    {
        if(a[itr->s] == itr->f)
            ans++;
    }
    fout << ans/2 << "\n";
    return 0;
}

