#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge(int arr[], int arr2[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2], L1[n1], R1[n2]; 
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i]; 
        L1[i] = arr2[l + i]; 
    }
    for (j = 0; j < n2; j++) 
    {
        R[j] = arr[m + 1+ j]; 
        R1[j] = arr2[m + 1 + j]; 
    }
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] < R[j]) 
        { 
            arr[k] = L[i]; 
            arr2[k] = L1[i];
            i++; 
        }
        else if (L[i] == R[j])
        {
            if(L1[i] <= R1[j])
            {
                arr[k] = L[i]; 
                arr2[k] = L1[i];
                i++;
            }
            else
            {
                arr[k] = R[j]; 
                arr2[k] = R1[j];
                j++;
            }
        }
        else
        { 
            arr[k] = R[j]; 
            arr2[k] = R1[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        arr2[k] = L1[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        arr2[k] = R1[j];
        j++; 
        k++; 
    } 
} 
void mergesort(int arr[],int arr2[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergesort(arr, arr2, l, m); 
        mergesort(arr, arr2, m+1, r); 
  
        merge(arr, arr2, l, m, r); 
    } 
} 


int main()
{
	int n, i;
	scanf("%d", &n);
	int arr[n], arr2[n];
	for(i=0;i<=n;i++)
    {
        scanf("%d ", &arr[i]);
        scanf("%d /n", &arr2[i]);
    }
    mergesort(arr, arr2, 0, n-1);
    int j=arr2[0], count = 1;
    for(i=1;i<n;i++)
    {
        if(arr2[i]>=j && arr[i]<=j)
            continue;
        else
        {
            j = arr2[i];
            count+=1;
        }
    }
    printf("%d", count);
	return 0;
}