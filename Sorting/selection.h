/*
* Selection Sort: This function sorts an array using the selection sort algorithm.
* Parameters:
* - arr: Pointer to the array to be sorted.
* - length: The length of the array.
*/



void selectionSorting(int *arr, int length){
    int i,j,k, temp;
    for (i = 0; i < length-1; i++){
        k = i;
        for (j = i+1; j < length; j++){
            if (*(arr+j) < *(arr+k)){
                k = j;
            }
        }
        if(k != i){
            temp = *(arr+i);
            *(arr+i) = *(arr+k);
            *(arr+k) = temp;

        }
    }
}

