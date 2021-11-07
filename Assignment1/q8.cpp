//Areeb Sajjad 20i-0904 Section A- Assignment 1

// Write a program that takes a three 2D pointer array and find the following by implementing the
// function for each of the following task:

// Find the same rows in each array.
// void FindSameRows(int **A1, int **A2, int **A3);

#include<iostream>
using namespace std;
int FindSameRows(int ** m1, int ** m2,int ** m3,int rows,int cols){
int count=0;
bool check=false;
    for(int i=0,x=0;i<rows;i++,x++){
        for(int j=1+x;j<rows;j++){
            for(int k=0;k<cols;k++){
                if(m1[i][k]!=m1[i+j][k]){
                    check=false;
                    break; 
                }
                else
                    check=true;
            }
            if(check==true){
                count+=2;
                check=false;
            }
        }

    }	
    return count;
}
int main(){
    int ** m1 = new int*[6];// 6x4 matrix
	int ** m2 = new int*[6];
	int ** m3 = new int*[6];
	for (int i =0;i<6;i++){
		m1[i] = new int[4];
		m2[i] = new int[4];
		m3[i] = new int[4];
	}
    int counter = 2;

	for(int i =0;i<6;i++){
		for (int j=0;j<4;j++){
			m1[i][j] = counter;
			m2[i][j] = 2 * counter;
			m3[i][j] = 3 * counter;
			counter++;
		}
	}
    counter = 1;
	for (int j=0;j<4;j++){
			m1[1][j] = m2[2][j] = m3[3][j] = m1[3][j] = m2[0][j] = m3[1][j] = counter ;
	}

	
	int count = FindSameRows(m1,m2,m3,6,4);
    cout << count;
    return 0;


}