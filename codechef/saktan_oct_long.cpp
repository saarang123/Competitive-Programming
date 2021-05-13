#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int t, i, j, n,k, xi, yi, m, q;
	cin >> t;
	while(t--)
	{
	    cin >> n >> m >> q;
	    int arr[n], arr2[m];
	    for(i=0; i<n; i++)
            arr[i]=0;
        for(j=0; j<m; j++)
            arr2[j]=0;
	    for(k=0; k<q; k++)
	    {
	        cin >> xi >> yi;
	        xi--, yi--;
	        arr[xi]++, arr2[yi]++;
	    }

        cout << "\n";
	    for(i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        for(i=0; i<m; i++)
            cout << arr2[i] << " ";
        cout << "\n";
        int ans = n*m;
        for(i=0; i<n; i++)
        {
            if(arr[i]%2==1)
                ans-=arr[i];
            else if(arr[i]!=0)
                ans-=(n-arr[i]);
        }
        for(i=0; i<m; i++)
        {
            if(arr2[i]%2==1)
                ans-=arr2[i];
            else if(arr2[i]!=0)
                ans-=(n-arr2[i]);
        }
        cout << ans << "\n";
	}
}
