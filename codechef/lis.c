#include<bits/stdc++.h>
using namespace std;

int lis( int arr[], int n )
{
    int l[n];
    l[0] = 1;
    for (int i = 1; i < n; i++ )
    {
        l[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && l[i] < l[j] + 1)
                l[i] = l[j] + 1;
    }
    return *max_element(l, l+n);
}

int main()
{
    int arr[] = { 1, 2, 5, 7, 3, 6, 4 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}