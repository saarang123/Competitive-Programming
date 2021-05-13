#include <stdio.h>
void merge(int long arr[], int long l, int long m, int long r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int long L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int long arr[], int long l, int long r) 
{ 
    if (l < r) 
    { 
        int long m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
int long search2(int long arr[], int long l, int long r, int long x)
{
    if(arr[0]>x)
        return 1000000;
    if(l<r)
    {
        int mid = (l+r-1)/2;
        if(arr[mid] == x)
            return 0;
        if(arr[mid] > x)
            return search2(arr, l, mid-1, x);
        return search2(arr, mid+1, r, x);
    }
    else
    {
        if(arr[l] <= x)
            return(x-arr[l]);
        else if(arr[l-1] <= x)
            return(x-arr[l-1]);
    }
    
}
int long search1(int long arr[], int long l, int long r, int long x)
{
    if(l<r)
    {
	int mid = (l+r-1)/2;
	if(arr[mid] == x)
	    return 0;
	if(arr[mid] > x)
	    return search1(arr, l, mid-1, x);
	return search1(arr, mid+1, r, x);
    }
    else
    {
	if(arr[l] >= x)
	    return(arr[l]-x);
	else if(arr[l+1] >= x)
	    return(arr[l+1]-x);
    }
    return 1000000;
}

int main()    
{
    int long n, x, y, i, j, temp, ans=1000001;
    scanf("%ld %ld %ld", &n, &x, &y);
    int long l[n][2], v[x], w[y];
    for(i=0; i<n; i++)
	scanf("%ld %ld \n", &l[i][0], &l[i][1]);
    for(i=0; i<x; i++)
	scanf("%ld ", &v[i]);
    for(i=0; i<y; i++)
	scanf("%ld ", &w[i]);
    mergeSort(v, 0, x-1);
    mergeSort(w, 0, y-1);
    for(i=0; i<n; i++)
    {
        temp = l[i][1] - l[i][0] + 1;
	    int long bg = search2(v, 0, x-1, l[i][0]);
	    int long eg = search1(w, 0, y-1, l[i][1]);
	    temp+=bg+eg;
	    if(temp<=ans)
	        ans = temp;
    }
    printf("%ld \n", ans);
    return 0;
}