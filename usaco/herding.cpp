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
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    //freopen("input.txt", "r", stdin);
    int a[3];
    int pres, mi=1000000005, ma = 0;
    fin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if (a[2]==a[0]+2)
        fout << "0\n";
    else if (a[1]==a[0]+2 || a[2]==a[1]+2)
        fout << "1\n";
    else
        fout << "2\n";
    fout << max(a[1]-a[0], a[2]-a[1]) - 1 << "\n";
    return 0;
}
