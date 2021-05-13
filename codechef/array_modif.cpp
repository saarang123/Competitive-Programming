#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t, n, i, j;
    ll k;
	cin >> t;
	while(t--)
	{
	    cin >> n >> k;
	    int a[n];
	    for(i=0; i<n; i++)
	        cin >> a[i];
	    /*for(i=0; i<n; i++)
	    {
	       cout << a[i] << " ";
	    }
	    cout << endl; */
	    int l = (k/n)%3;  //The same elements are XORed 2 twice every N elements. Every 3 pairs of N elements, they retain original positions
	    int r = k%n;    //Extra elements to be XORed after pairs are done
	    //cout << l << " " << r << endl;
	    for(j=0; j<l; j++)
	    {
	        for(i=0; i<n; i++)
	        {
	            a[i] = (a[i]^a[n-1-i]);
	            //a[n-1-i] = (a[i]^a[n-1-i]);
	        }
	        
	    }
	    /*for(int f=0; f<n; f++)
	    {
	        cout << a[f] << " ";
	    }
	    cout << endl;*/
	    for(j=0; j<r; j++)
	    {
	        a[j] = (a[j]^a[n-1-j]);
	    }
	    if(n%2==1 && k>n/2)
	        a[n/2] = 0;
	    for(i=0; i<n; i++)
	    {
	       cout << a[i] << " ";
	    }
	    cout << "\n";
	}
}