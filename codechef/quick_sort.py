def partition(arr, low, high):
    i = low-1
    p = arr[high]
    for j in range(low, high):