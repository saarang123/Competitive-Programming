#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string s;
int cnt[26],sum;
ll ans;
int main()
{
	cin>>s;
	ans=1;
	for(char &i:s)
	{
		cnt[i-'a']++;
		sum++;
		ans+=sum-cnt[i-'a'];
	}
	printf("%lld\n",ans);
	return 0;
}