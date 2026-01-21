
/*
* Linear Search: This function searches for a given value in an array using the linear search algorithm.
* It returns the index of the value if found, otherwise returns -1.
* Parameters:
* - arr: Pointer to the array to be searched.
* - v: The value to be searched.
* - length: The length of the array.
*/



int LinearSearch(int *arr, int v, int length){
    int index=-1;
    for(int i=0; i<length;i++){
        if(*(arr+i) == v) return i;
    }
    return index;
}


 
