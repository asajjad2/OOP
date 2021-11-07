// possessing the highest value. Split the element into two parts where first part contains
// the next highest value in the array and second part hold the required additive entity to get the
// highest value. Return the array index value. Consider the negative numbers as well.
// Input: 4 8 6 3 2 Output: 4 6 2 6 3 2
// Note: use index number to return a value from an array

#include <iostream>
#include <cmath>

void q2(){
	int s;
	cout << "Please input size of array\n";
	cin >> s;
	int arr1[s],index1;
	cout << "Please input array elements\n";
	for(int i=0;i<s;i++)
	{
		cin >> arr1[i];
		while(arr1[i]<=0){
			cout << "element needs to be non-negative, input again!\n";
			cin >> arr1[i];
		}
	}
	int highest = arr1[0],secondHighest=arr1[0];
	for(int j=0;j<s-1;j++){
		if(arr1[j]<arr1[j+1]){
			highest=arr1[j+1];
			index1=j+1;
		}

	}
	for(int k=0;k<s-1;k++){
		if((arr1[k]<arr1[k+1])&&(arr1[k+1]!=highest))
			secondHighest=arr1[k+1];
	}
	int arr2[s+1];
	cout << "the new array formed is \n";
	arr2[index1]=secondHighest;
	for(int i=0;i<s+1;i++){
		if(i==index1)
			continue;
		else if (i==s)
			arr2[i]=highest-secondHighest;
		else
			arr2[i]=arr1[i];
	}
	for(int i=0;i<=s;i++)
		cout << arr2[i] << "\t" ;
}

int main(){

    q2();

    return 0;
}