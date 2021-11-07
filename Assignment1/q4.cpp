//Areeb Sajjad 20i-0904 Section A- Assignment 1

// Write a program that takes a 2D pointer array and calculate sum of even and odd using pointer
// notation of the array.



#include <iostream>
using namespace std;
int EvenSum(int ** array, int r,int l){
    int sum=0;
	for(int i=0;i<r;i++){
        for(int j=0;j<l;j++){
            if(*(*(array+i)+j)%2==0)
                sum+=*(*(array+i)+j);
        }

    }
    return sum;
}
int OddSum(int ** array,int r,int l){
	int sum=0;
	for(int i=0;i<r;i++){
        for(int j=0;j<l;j++){
            if(*(*(array+i)+j)%2==1)
                sum+=*(*(array+i)+j);
        }

    }
    return sum;
}

