#include <iostream>
#include "Student.h"
using namespace std;

void printArray(Student s[], int length){
    cout << *(s[0].getCgpa());
    for (int i =1; i < length; i++){
        cout << ", " << *(s[i].getCgpa());
    }
    cout << endl;
}

int main()
{
    Student s[5];

    float cgpa[] = {2.9,3.2,2.8,3.9,3.4};

    for (int i = 0; i < 5; i++){
        s[i].setCgpa(cgpa+i);
    }



    cout << "\nlinear search : ";
    int index = LinearSearch(s,3.2,5);
    if(index == -1) cout << "Not found" << endl;
    else cout << "value found in " << index << endl;

    cout << "\nthe default array : \n";
    printArray(s,5);
    bubbleSorting(s,5);
    cout << "\nafter bubble sort : \n";
    printArray(s,5);

    insertionSort(s,5);
    cout << "\nafter insertion sort : \n";
    printArray(s,5);

    selectionSorting(s,5);
    cout << "\nafter insertion sort : \n";
    printArray(s,5);

    cout << "\nbinary search : ";
    index = binarySearch(s,3.9,5);
    if(index == -1) cout << "Not found" << endl;
    else cout << "value found in " << index << endl;


    return 0;
}
