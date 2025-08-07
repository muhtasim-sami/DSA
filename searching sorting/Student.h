#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student{
    private:
        char name[20];
        int id;
        float *cgpa;
    public:
        Student(){

        }
        void setCgpa(float *cgpa){
            this->cgpa = cgpa;
        }

        float *getCgpa() {return cgpa;}
};


int LinearSearch(Student s[], float v, int length){
    int index=-1;
    for(int i=0; i<length;i++){
        if(*s[i].getCgpa() == v) return i;
    }

    return index;
}

int binarySearch(Student s[], float v, int length){
    int first = 0, last = length - 1 , index = -1;
    int mid = (first + last)/2;

    while (true){
        int mid = (first + last)/2;

        if (*(s[mid].getCgpa()) == v)
            index = mid;
            break;
        if (first > last) break;
        else if (v > *(s[mid].getCgpa())) first = mid+1;
        else if (v < *(s[mid].getCgpa())) last = mid-1;

        if (*(s[mid].getCgpa()) == v) return mid;
    }
    return index;
}

int selectionSorting(Student s[], int length){
    int i,j,k;
    float temp;
    for (i = 0; i < length-1; i++){
        k = i;
        for (j = i+1; j < length; j++){
            if (*(s[j].getCgpa()) < *(s[k].getCgpa())){
                k = j;
            }
        }
        if(k != i){
            temp = *(s[i].getCgpa());
            *(s[i].getCgpa()) = *(s[k].getCgpa());
            *(s[k].getCgpa()) = temp;

        }
    }
}


void bubbleSorting(Student s[], int length){
    float temp;
    int i,j;
    for ( i = 0; i < length-1; i++){
        for ( j = 0; j < length-i-1; j++){
            if (*(s[j].getCgpa()) > *(s[j+1].getCgpa())){
                temp = *(s[j].getCgpa());
                *(s[j].getCgpa()) = *(s[j+1].getCgpa());
                *(s[j+1].getCgpa()) = temp;
            }
        }
    }
}

void insertionSort(Student s[], int length){
    int i,j;
    float k;
    for ( i = 1; i < length-1; i++){
        k = *(s[i].getCgpa());

        for(j = i-1; j >=0 && *(s[j].getCgpa()) > k; j--){
            *(s[j+1].getCgpa()) = *(s[j].getCgpa());
        }
        *(s[j+1].getCgpa()) = k;
    }
}


#endif // STUDENT_H_INCLUDED
