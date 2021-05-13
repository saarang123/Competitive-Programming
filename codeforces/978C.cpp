#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;

int search(ll arr[], int l, int r, ll x)
{
    if(l<r)
    {
        int mid = (l+r-1)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            return search(arr, l, mid-1, x);
        return search(arr, mid+1, r, x);
    }
    else
    {
        if(arr[l] <= x)
            return l;
        else if(arr[l-1] <= x)
            return l-1;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, m, i, j;
	cin >> n >> m;
	ll a[n+1], b[m];
	a[0]=0;
	for(i=1; i<=n; i++)
	{
	    cin >> a[i];
	    a[i]+=a[i-1];
	}
	for(i=0; i<m; i++)
	{
	    cin >> b[i];
	    int ind = search(a, 0, n, b[i]);
	    if(b[i]==a[ind])
	        cout << ind << " " << b[i] - a[ind-1] << "\n";
	    else
    	    cout << ind+1 << " " << b[i] - a[ind] << "\n";
	}
	return 0;
}