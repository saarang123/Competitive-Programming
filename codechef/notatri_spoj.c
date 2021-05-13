include <stdio.h>
 
int binary_search(int long arr[], int n, int l, int r, int long x)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        if (arr[mid] == x)
            return (n-mid);
        if (arr[mid] > x)
            return binary_search(arr, n, l, mid - 1, x);
        return binary_search(arr, n, mid + 1, r, x);
    }
    else if(l==r)
    {
        if(arr[l] >=  x)
            return(n-l);
        else
            return(n-l-1);
    }
}
 
 
void merge(int long arr[], int l, int m, int r)
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
void mergeSort(int long arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
 
int main()
{
    int n = 0, i,j;
    scanf("%d", &n);
    while(n!=0)
    {
        int long l[n], x, c=0;
        for(i = 0; i<n; i++)
            scanf("%ld", &l[i]);
        mergeSort(l, 0, n-1);
        for(i = 0; i<n; i++)
        {
            for(j = i+1; j<n; j++)
            {
                x = l[i] + l[j] + 1;
                c += binary_search(l, n, 0, n-1, x);
            }
        }
        printf("%ld \n", c);
        scanf("%d", &n);
    }
    return 0;
}