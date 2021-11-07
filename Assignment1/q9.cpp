//Areeb Sajjad 20i-0904 Section A- Assignment 1

// Write a program that takes a three 2D pointer array and find the following by implementing the
// function for each of the following task:

// Rotate all three arrays up to 90 degrees in clockwise direction.
// void RotateArrays(int **A1, int **A2, int **A3);

void RotateArrays( int **m1 ,int **m2 ,int **m3,int s1 , int s2,int s3){
    int temp;
    for (int i=0; i< s1/2; i++) {
        for (int j=i; j<s1-i-1; j++) {
            temp=*(*(m1+i)+j);
            *(*(m1+i)+j) = *(*(m1+(s1-j-1))+i);
            *(*(m1+(s1-j-1))+i) = *(*(m1+(s1-i-1))+(s1-j-1));
            *(*(m1+(s1-i-1))+(s1-j-1)) = *(*(m1+(j))+(s1-i-1));
            *(*(m1+(j))+(s1-i-1)) = temp;
        }
    }
    for (int i=0; i< s2/2; i++) {
        for (int j=i; j<s2-i-1; j++) {
            temp=*(*(m2+i)+j);
            *(*(m2+i)+j) = *(*(m2+(s2-j-1))+i);
            *(*(m2+(s2-j-1))+i) = *(*(m2+(s2-i-1))+(s2-j-1));
            *(*(m2+(s2-i-1))+(s2-j-1)) = *(*(m2+(j))+(s2-i-1));
            *(*(m2+(j))+(s2-i-1)) = temp;
        }
    }
    for (int i=0; i< s3/2; i++) {
        for (int j=i; j<s3-i-1; j++) {
            temp=*(*(m3+i)+j);
            *(*(m3+i)+j) = *(*(m3+(s3-j-1))+i);
            *(*(m3+(s3-j-1))+i) = *(*(m3+(s3-i-1))+(s3-j-1));
            *(*(m3+(s3-i-1))+(s3-j-1)) = *(*(m3+(j))+(s3-i-1));
            *(*(m3+(j))+(s3-i-1)) = temp;
        }
    }
}