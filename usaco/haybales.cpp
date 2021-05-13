#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int lower(int a[], int x, int l, int r)
{
    while(l<r)
    {
        //cout << l << " " << r << "\n";
        int mid = (l+r)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            r = mid-1;
        else
            l = mid+1;

    }
    if(l>=r)
    {
        if(a[l]<=x)
            return l;
        else if(a[l-1]<=x)
            return l-1;
    }
    return -1;
}

int upper(int a[], int x, int l, int r)
{
    while(l<r)
    {

        //cout << l << " " << r << "\n";
        int mid = (l+r)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    //cout << l << " " << r << "\n";
    if(a[l]>=x)
        return l;
    else if(a[l+1]>=x)
        return l+1;
    return -1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j, q, a, b;
    fin >> n >> q;
    int hay[n];
    for(i=0; i<n; i++)
        fin >> hay[i];
    sort(hay, hay+n);
    while(q--)
    {
        fin >> a >> b;
        int l = lower(hay, b, 0, n-1);
        int r = upper(hay, a, 0, n-1);
        if(l!=-1 && r!=-1 &&  r<n && l<n)
            fout << l-r+ 1<< "\n";
        else
            fout << 0 << "\n";

        //cout << lower(hay, b, 0, n-1) << " " << upper(hay, a, 0, n-1) << "\n";

    }
    return 0;
}
