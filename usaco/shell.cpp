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
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j, a[3] = {1,2,3}, w1=0, w2=0, w3=0;
    fin >> n;
    while(n--)
    {
        int c;
        fin >> i >> j >> c;
        swap(a[i-1], a[j-1]);
        if(a[c-1]==1)
            w1+=1;
        else if(a[c-1]==2)
            w2+=1;
        else if(a[c-1]==3)
            w3+=1;
    }
    fout << max(max(w1,w2), w3) << endl;
    return 0;
}
