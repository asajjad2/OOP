// Problem 4:
// Define and initialize five arrays of integer types each having 6 elements and an array of pointers
// p of size 5. Store the starting address of each array to array of pointers p. call the function and
// initialize the values of these five arrays randomly using for loop and p inside this function.
// Finally display the sum of each individual array.

#include <iostream>
#include <cmath>


void q4(){
	int arr1[6];
	int arr2[6];
	int arr3[6];
	int arr4[6];
	int arr5[6];
	int *ptrarr[5];
	ptrarr[0]=arr1;
	ptrarr[1]=arr2;
	ptrarr[2]=arr3;
	ptrarr[3]=arr4;
	ptrarr[4]=arr5;
	for(int i=0;i<6;i++){
		*(ptrarr[0]+i)=rand()%100;
		*(ptrarr[1]+i)=rand()%100;
		*(ptrarr[2]+i)=rand()%100;
		*(ptrarr[3]+i)=rand()%100;
		*(ptrarr[4]+i)=rand()%100;
	}
	for (int i=0;i<6;i++){
		cout << *(ptrarr[0]+i) << "\t";
	}
	cout << endl;
	for (int i=0;i<6;i++){
		cout << *(ptrarr[1]+i) << "\t";
	}
	cout << endl;
	for (int i=0;i<6;i++){
		cout << *(ptrarr[2]+i) << "\t";
	}
	cout << endl;
	for (int i=0;i<6;i++){
		cout << *(ptrarr[3]+i) << "\t";
	}
	cout << endl;
	for (int i=0;i<6;i++){
		cout << *(ptrarr[4]+i) << "\t";
	}
	cout << endl;
	int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
	for(int i=0;i<6;i++){
		sum1+=*(ptrarr[0]+i);
		sum2+=*(ptrarr[1]+i);
		sum3+=*(ptrarr[2]+i);
		sum4+=*(ptrarr[3]+i);
		sum5+=*(ptrarr[4]+i);
	}
	cout << "sum of array 1 is "<< sum1 << endl;
	cout << "sum of array 2 is "<< sum2 << endl;
	cout << "sum of array 3 is "<< sum3 << endl;
	cout << "sum of array 4 is "<< sum4 << endl;
	cout << "sum of array 5 is "<< sum5 << endl;

}

int main(){

    q4();

    return 0;

}