//Areeb Sajjad i200904 - Assignment 1 - Section A

// Write a program to take two string inputs from user and call the recursive function to find whether
// the second string is a subsequent of the first.
// void CheckSubsequent(char *str1, char *str2, int i, int j);

int CheckSubSequence(char *str1, char *str2, int i, int j){
    if(*str1!=*str2){
        if(*str2==*(str2+(j-1)))
            return 0;
        else 
            return CheckSubSequence(str1+1,str2+1,i,j);
    }
    else if(*str1==*str2){
        if(*str2==*(str2+(j-1)))
            return 1;
        else
            return 1 * CheckSubSequence((str1+1),(str2+1),i,j);
    }
    else
        return 0;
}
