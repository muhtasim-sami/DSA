
/*
* Binary Search: This function searches for a given value in a sorted array using the binary search algorithm.
* It returns the index of the value if found, otherwise returns -1.
* Parameters:
* - arr: Pointer to the sorted array to be searched.
* - v: The value to be searched.
* - length: The length of the array.
*/



int binarySearch(int *arr, int v, int length){
    int first = 0, last = length - 1 , index = -1;
    int mid = (first + last)/2;

    while (true){
        int mid = (first + last)/2;

        if (*(arr+mid) == v)
            index = mid;
            break;
        if (first > last) break;
        else if (v > *(arr+mid)) first = mid+1;
        else if (v < *(arr+mid)) last = mid-1;

        if (*(arr+mid) == v) return mid;
    }
    return index;
}


 
