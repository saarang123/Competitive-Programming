#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
void swap(long long int* a,long long int* b) 
{ 
    long long int t = *a; 
    *a = *b; 
    *b = t; 
}

long long int partition(long long int a[],long long int m,long long int n)
{
	long long int pivot=a[n],i,j;
	i=m-1;
	for(j=m;j<n;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[n]);
	return i+1;
}

void quicksort(long long int b[],long long int m,long long int n)
{
	if(m<n)
	{
		long long int pivot=partition(b,m,n);
		quicksort(b,m,pivot-1);
		quicksort(b,pivot+1,n);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[1000001];
		scanf("%s",s);
		long long int a[26]={0};
		long long int i,j,len=strlen(s);
		for(i=0;i<len;i++)
		{
			long long int temp=s[i];
			a[temp-65]++;
		}
		quicksort(a,0,25);
		long long int min=INT_MAX;
		for(j=1;j<=26;j++)
		{
			if(len%j==0)
			{
				long long int count=0;
				long long int temp1=j,temp2=len/j,i=25;
				while(temp1!=0)
				{
					if(a[i]<temp2)
					count+=temp2-a[i];
					if(min<count)
					break;
					temp1--;
					i--;
				}
				if(min>count)
				{
					min=count;
				}
				 
			}
		}
		printf("%lld\n",min);
	}
	return 0;
}