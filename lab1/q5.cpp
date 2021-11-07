// Problem 5:
// In the previous task we can consider p as a 2D matrix. However, in that case our number of rows
// (which were 5 as there were 5 arrays stored in p) and number of columns (which were 6 as each
// array had 6 elements) were fixed. In this question we will extend the previous question and make
// our number of columns variables. To do this, instead of using arrays of fixed size of 6 elements
// allocated on stack, we will make each array to have ncol (passed as argument to the function)
// elements and store them on heap using new operator. Once again store the starting address of
// each array to array of pointers p. Next, initialize the values of these five arrays randomly using
// for loop and p. Finally display the sum of each individual array.

#include <iostream>
#include <cmath>


void q5(int ncol){
	int sum=0;
	int *ptr = new int[ncol];
	for(int i=0;i<ncol;i++){
		*(ptr+i)=rand()%100;
		cout << *(ptr+i) << "\t";
		sum+=*(ptr+i);
	}
	cout << endl;
	cout << "sum is " << sum << endl;
}

int main(){

    int ncol;

    for(int i=0;i<5;i++){
		cout << "please input array columns\n";
		cin >> ncol;
		q5(ncol);
	}

    return 0;

}