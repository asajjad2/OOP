//Areeb Sajjad 20i-0904 Section A- Assignment 1

// Write a program that takes a three 2D pointer array and find the following by implementing the
// function for each of the following task:

// Are there any equal arrays among these?
// void CheckEqualArrays(int **A1, int **A2, int **A3)

bool CheckEqualArrays(int ** m1, int ** m2,int ** m3,int rows,int cols){
	bool equal1=true,equal2=true,equal3=true,equal;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m1+i)+j)!=*(*(m2+i)+j))
                equal1=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m2+i)+j)!=*(*(m3+i)+j))
                equal2=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m1+i)+j)-*(*(m3+i)+j))
                equal3=false;
        }
    }
    equal=equal1||equal2||equal3;
    return equal;
}
