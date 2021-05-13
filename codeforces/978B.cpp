#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,i, j;
	cin >> n;
	string s;
	cin >> s;
	int cnt=0;
	j=0;
	for(i=0; i<n; i++)
	{
 	    if(s[i]=='x')
	        j++;
	    else
	    {
	        if(j>2)  cnt+=j-2;
	        j=0;
	    }
	}
	if(j>2)
	    cnt+=j-2;
	cout << cnt << "\n";
	return 0;
}
