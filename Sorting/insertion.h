
/*
* Insertion Sort: This function sorts an array using the insertion sort algorithm.
* Parameters:
* - arr: Pointer to the array to be sorted.
* - length: The length of the array.
*/


void insertionSort(int *arr, int length){
    int i,j,k;
    for ( i = 1; i < length-1; i++){
        k = *(arr+i);

        for(j = i-1; j >=0 && *(arr+j) > k; j--){
            *(arr+j+1) = *(arr+j);
        }
        *(arr+j+1) = k;
    }
}
