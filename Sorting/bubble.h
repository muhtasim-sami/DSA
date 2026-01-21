
/*
* Bubble Sort: This function sorts an array using the bubble sort algorithm.
* Parameters:
* - arr: Pointer to the array to be sorted.
* - length: The length of the array.
*/

void bubbleSorting(int *arr, int length){
    int temp,i,j;
    for ( i = 0; i < length-1; i++){
        for ( j = 0; j < length-i-1; j++){
            if (*(arr+j) > *(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}
