#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second


int distinct(int arr[], int n) 
{ 
    int cnt=0;
    for (int i=0; i<n; i++) 
    { 
        int j; 
        for (j=0; j<i; j++) 
           if (arr[i] == arr[j]) 
               break; 
        if (i == j)
            cnt++;
    } 
    return cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, k, t, i, j;
	cin >> n;
	int a[n];
	for(i=0; i<n; i++)
	    cin >> a[i];
	reverse(a, a+n);
	cout << distinct(a, n) << "\n";
	vector<int> v;
	for (int i=0; i<n; i++) 
    { 
        int j; 
        for (j=0; j<i; j++) 
           if (a[i] == a[j]) 
               break; 
        if (i == j)
            v.push_back(a[i]);
    }
    reverse(v.begin(), v.end());
    for(i=0; i<v.size(); i++)
        cout << v[i] << " ";
	return 0;
}