// Write a function that takes two arguments as input: a pointer to integer p and size s. You are
// required to allocate memory for an array with s elements of type int using new operator. As your
// next step, randomly initialize all the elements of the array and then update each element value
// with its square, i.e., replace each element value with its square.
// Question for your thought why we are passing the pointer by reference into the function?

#include <iostream>
#include <cmath>

void q3(int *p,int s){
	p = new int[s];
	for(int i=0;i<s;i++)
	{
		*(p+i)=rand()%100;
	}
	for(int k=0;k<s;k++)
	{
		cout << *(p+k) << endl;
	}
	for(int j=0;j<s;j++)
	{
		*(p+j) = pow(*(p+j),2) ;
	}
	for(int k=0;k<s;k++)
	{
		cout << "square of " << k+1 << "th element is " << *(p+k) << endl;
	}
	delete p;
}


int main(){

    int *p,s;
	cout << "Input s\n";
	cin >> s;
	q3(p,s);

    return 0;
}