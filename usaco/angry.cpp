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
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int i,j, n, k;
    fin >> n >> k;
    int a[n];
    for(i=0; i<n; i++)
    {
        fin >> a[i];
    }
    sort(a, a+n);
    int min = 0;
    int max = 500000000;
    while(min!=max)
    {
        int mid = (min+max)/2;
        int used=0;
        int last=0;
        while(last<n)
        {
            used++;
            int cur=last+1;
            while(cur<n && a[cur]-a[last] <= 2*mid)
                cur++;
            last = cur;
        }
        if(used<=k)
            max = mid;
        else
            min = mid+1;
    }
    fout << min << "\n";
}
