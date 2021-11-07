// Problem 1:
// Write a c++ program to accept five integer values from the keyboard. Store these five values in
// an array using pointer. Then print all the elements of an array in reverse order.
// Note: use index number to return a value from an array


#include <iostream>
#include <cmath>
using namespace std;
void q1(){
	int n=1,size=5;
	int arry[size];
	int *p = arry;
	for(int i=0;i<size;i++,n++)
	{
		cout << "Please input the " << n << "th element\n";
		cin >> *(p+i);

	}
	for(int i=size-1;i>=0;i--)
	{
		cout << *(p+i) << endl;
	}


}

int main(){

    q1();

    return 0;
}
