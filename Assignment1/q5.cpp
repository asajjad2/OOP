//Areeb Sajjad 20i-0904 Section A- Assignment 1

// Write a program that takes a three 2D pointer array and find the following by implementing the
// function for each of the following task:

// Is the sum of any two arrays is equal to the 3 rd array?
// void CheckEqualSumArrays(int **A1, int **A2, int **A3);

bool CheckEqualSumArrays(int ** m1, int ** m2,int ** m3,int rows,int cols){
    bool sumEqual1=true,sumEqual2=true,sumEqual3=true,sumEqual;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m1+i)+j)+*(*(m2+i)+j)!=*(*(m3+i)+j))
                sumEqual1=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m2+i)+j)+*(*(m3+i)+j)!=*(*(m1+i)+j))
                sumEqual2=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m1+i)+j)+*(*(m3+i)+j)!=*(*(m2+i)+j))
                sumEqual3=false;
        }
    }
    sumEqual=((sumEqual1||sumEqual2)||sumEqual3);
    return sumEqual;
}