//Areeb Sajjad 20i-0904 Section A- Assignment 1

// Write a program that takes a three 2D pointer array and find the following by implementing the
// function for each of the following task:

// Is the difference of any two arrays is equal to the 3 rd array?
// void CheckDifferentArrays(int **A1, int **A2, int **A3);

bool CheckDifferentArrays(int ** m1, int ** m2,int ** m3,int rows,int cols){
    bool differ1=true,differ2=true,differ3=true,differ4=true,differ5=true,differ6=true,differ;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m1+i)+j)-*(*(m2+i)+j)!=*(*(m3+i)+j))
                differ1=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m2+i)+j)-*(*(m3+i)+j)!=*(*(m1+i)+j))
                differ2=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m1+i)+j)-*(*(m3+i)+j)!=*(*(m2+i)+j))
                differ3=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m2+i)+j)-*(*(m1+i)+j)!=*(*(m3+i)+j))
                differ4=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m3+i)+j)-*(*(m2+i)+j)!=*(*(m1+i)+j))
                differ5=false;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(*(*(m3+i)+j)-*(*(m1+i)+j)!=*(*(m2+i)+j))
                differ6=false;
        }
    }
    differ=(differ1||differ2||differ3||differ4||differ5||differ6);
    return differ;

}