//Areeb Sajjad 20i-0904 Section A - Assignment 1

// Write a recursive function for the following problem. You need to change the location of the
// entries with indices between the two boundaries of the char array.
// void ChangeLocation(char *Array, int b1, int b2);

void ChangeLocation(char *arr, int b1, int b2){
	if(b1==-90){ //base condition
		return;
	}
	else{
		int temp=*(arr+b1-1);	
		*(arr+b1-1)=*(arr+b2-1);
		*(arr+b2-1)=temp;
		b1=-90;
		ChangeLocation(arr,b1,b2);
	}
}
