//Areeb Sajjad 20i-0904 Section A - Assignment 1

// Write a program to take input in dynamic integer array and show the occurrence of each number
// in the array in descending order using recursive function.
// void FindOccurances(int *A, int i);

#include <iostream>
using namespace std;
int Occur(int *A, int size, int x){  //checks for the occurences of a number
    
    if (size == 0) 
        return 0;
    else if(A[size-1]!=x)
        return Occur(A,size-1,x);
    else
        return 1 + Occur(A, size-1, x);
}
int *FindOccurances(int *A, int size){ //sends each number one by one
    int *ptr;
    ptr = new int[size]{0};
    for(int i=0;i<size;i++){
        ptr[size-i-1]+=Occur(A,size,A[i]);
    }
    /*for(int i=0;i<size;i++){
        cout << ptr[i];
    }*/
    return ptr;
}
