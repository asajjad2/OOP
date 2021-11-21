#include <iostream>
#include <cmath>
using namespace std;
struct Rectangle{

        int x1;
        int x2;
        int x3;
        int x4;
        int y1;
        int y2;
        int y3;
        int y4;
        int area;

        Rectangle(){
            x1=x2=x3=x4=y1=y2=y3=y4=area=0;
        }

        void getInput(){
            cin >> x1;
            cin >> y1;
            cin >> x2;
            cin >> y2;
            cin >> x3;
            cin >> y3;
            cin >> x4;
            cin >> y4;
        }

        void getOutput(){
            cout << area << endl; 
        }

        void setArea(){
            area = sqrt(pow(y2-y1,2)+pow(x2-x1,2))*sqrt(pow(y3-y2,2)+pow(x3-x2,2));
        }

        Rectangle*SortArea(Rectangle *ptr,int size){
            Rectangle temp;
            for(int i=0;i<size-1;i++){ //sorting
                if(ptr[i].area>ptr[i+1].area){
                    temp=ptr[i+1];
                    ptr[i+1]=ptr[i];
                    ptr[i]=temp;
                }
            }
            return ptr;
        }

        bool overlap(Rectangle *ptr,int size){
            if(x1<=ptr[size-1].x2&&x1>=ptr[size-1].x1){
                if(y1<=ptr[size-1].y1&&y1>=ptr[size-1].y4)
                    return true;
            }
            else if(x2<=ptr[size-1].x2&&x2>=ptr[size-1].x1){
                if(y2<=ptr[size-1].y1&&y2>=ptr[size-1].y4)
                    return true;
            }
            else if(x3<=ptr[size-1].x2&&x3>=ptr[size-1].x1){
                if(y3<=ptr[size-1].y1&&y3>=ptr[size-1].y4)
                    return true;
            }
            else if(x4<=ptr[size-1].x2&&x4>=ptr[size-1].x1){
                if(y4<=ptr[size-1].y1&&y4>=ptr[size-1].y4)
                    return true;

            }
            return false;
        }
        
};

int main(){
    int num;
    cout << "Please input the number of rectangles\n";
    cin >> num;
    while(num<=1){
        cout << "There should be atleast 2 rectangles\n";
        cin >> num;
    }
    Rectangle arr[num],*p,x;    //rectangles generated
    p=arr;
    cout << "Please input the coordinates of each rectangle, from top left as (x1,y1) and moving clockwise.\n";
    for(int i=0;i<num;i++){ //initializing the coordinates
        cout << "Rectangle # " << i+1 << endl; 
        arr[i].getInput();
    }
    for(int i=0;i<num;i++){
        arr[i].setArea();
    }
    p=x.SortArea(p,num);
    for(int i=0;i<num;i++){
        p[i].getOutput();
    }
    cout << "Rectangles ";
    for(int i=0;i<num;i++){
        if(p[i].overlap(p,num)){
            cout << i << "\t";
        }
    }
    cout << "overlap with the largest rectangle" << endl;

    return 0;
}
