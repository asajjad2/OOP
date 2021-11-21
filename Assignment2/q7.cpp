#include <iostream>
using namespace std;
class Resource{};
class Task{

    private:
        int id;
        int dur;
        int s_Time; //start time of each task
        int e_Time; //end time of each task
        int late_start{0};
        int late_end{0};
        int numDep;
        int dep[10];
        char skill; 
        Resource res;
    public:
        void addTasks(){

            cout << "Please input task's id\n";
            cin >> id;
            cout << "Please input task duration in days\n";
            cin >> dur;
            cout << "Please input the number of tasks this task is dependant upon\n";
            cin >> numDep;
            if(numDep>0){
                cout << "Please input the id/ids of tasks this task is dependant upon\n";
                //int* dep = new int[numDep];
                for(int i=0;i<numDep;i++){

                    cout << "ID for dependant Task " << i+1 << endl;
                    cin >> dep[i];
 
                }
            }

            
        }
        int getStartTime() const{
            return s_Time;
        }
        int getEndTime() const{
            return e_Time;
        }
        int getID() const{
            return id;
        }
        /* int& getDep() const{
            return dep;
        } */
        int getNumDep() const{
            return numDep;
        }
        int getDuration() const{
            return dur;
        }
        int getLateEnd()const{
            return late_end;
        }
        int getLateStart()const{
            return late_start;
        }
        void setStartTime(int x){
            s_Time=x;
        }
        void setEndTime(int x){
            e_Time=x;
        }
        void findTime(Task *arr,int n){ //finds start time and end time of each task according to dependancies

                
                if(numDep==1){

                    for(int i=0;i<n;i++){
                        if(dep[0]==arr[i].getID()){
                            s_Time=arr[i].getEndTime();
                            e_Time=s_Time+dur;
                            break;
                        }
                    }
                }
                else if(numDep==0){
                    s_Time=0;
                    e_Time=s_Time+dur;
                }
                else{
                    int count=0;
                    //cout << arr[0].getEndTime();
                    int highest=arr[0].getEndTime();
                    //cout << highest;
                    for(int i=0;i<n;i++){

                        if(dep[count]==arr[i].getID()){

                            if(arr[i].getEndTime()>highest){
                                highest=arr[i].getEndTime();
                                if(count==numDep)
                                    break;
                                else
                                    count++;
                            }
                            else    
                                count++; 

                        }
                        else
                            continue;
                        
                    }
                    s_Time=highest;
                    e_Time=s_Time+dur; 
                    
                }
                

        } 
        /* void findBackwardsTime(Task* arr, int n){ //function to find late end late start time
            if(id==n){
                late_end=e_Time;
                late_start=late_end-dur;
            }
            else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<(arr[i].getNumDep());j++){
                        if(id==arr[i].dep[j]&&late_end==0){ //i.e. if current object is in the dependancy of another 
                            late_end=arr[i].getLateEnd();
                            late_start=late_end-dur;
                        }
                        else if(id==arr[i].dep[j]&&late_end!=0){
                            if(late_end>arr[i].getLateEnd()){
                                late_end=arr[i].getLateEnd();
                                late_start=late_end-dur;
                            }
                        }
                    }
                }
            }
        } */
        void setDuration(int x){
            dur=x;
        }
        void setTaskDuration(Task *arr,int n){
            int x;
            for(int i=0;i<n;i++){
                cout << "Input duration for Task#" << id << endl;
                cin >> x;
                arr[i].setDuration(x);
            }
            for(int i=0;i<n;i++){
                arr[i].findTime(arr,n);
            } 
        }
        void set_nth_TaskDuration(Task *arr, int n, int x){
            int i;
            for(i=0;i<n;i++){
                if(arr[i].getID()==x){
                    cout << "Input task's new duration\n";
                    int y;
                    cin >> y;
                    arr[i].setDuration(y);
                    break;
                }
            }
            arr[i].findTime(arr,n); 
        }
        void printTaskDependencyList(){
            if(numDep>0){
                cout << "Task #" << this->id << " is dependant upon tasks:\n";
                for(int i=0;i<numDep;i++){
                    cout << this->dep[i] << endl;
                }
            }
            
        }
        void display(){
            cout << "ID: " << id << endl; 
            cout << "Duration: " << dur << " days." << endl; 
            cout << "Start Time: " << s_Time << endl; 
            cout << "End Time: " << e_Time << endl; 
            this->printTaskDependencyList();
            //cout << "Late Start Time: " << late_start << endl; 
            //cout << "Late End Time: " << late_end << endl; 
        }


};

class Project{
    private:

        int id;
        int t;
        int numTasks; //duration of project
        Task* tasks;

    public:
    
        Project(){

            id=0;
            t=0;
            numTasks = 0;
            tasks = nullptr;

        }// default constructor
        Project(Task* ts, int n, int ID){
            
            tasks = ts;
            numTasks = n;
            id = ID;

        }//initialized the project with n tasks

        void completionTime(){

            Task* greatest; // would contain tasks with highest number of dependencies
            int highestDep=0,num=0;

            for(int i=1;i<numTasks;i++){ //find greatest number of dependencies
                if(tasks[i].getNumDep()>highestDep){
                    highestDep=tasks[i].getNumDep();
                }
            }
            for(int i=0;i<numTasks;i++){ //find number of tasks with the greatest dependency
                if(tasks[i].getNumDep()==highestDep){
                    num++;
                }
            }
            greatest = new Task[num];
            for(int i=0,j=0;i<numTasks;i++){ //find tasks
                if(tasks[i].getNumDep()==highestDep){
                    greatest[j]=tasks[i];
                    j++;
                }
            }
            int greatestTime=0;
            for(int i=0;i<num;i++){ //find greatest end time
                if(greatest[i].getEndTime()>greatestTime){
                    greatestTime=greatest[i].getEndTime();
                }
            }
            for(int i=0;i<num;i++){ //find task with greatest end time
                if(greatest[i].getEndTime()==greatestTime){
                    cout << greatest[i].getEndTime() << " days is the completion time for this project\n";
                    t = greatest[i].getEndTime();
                    break;
                }
            }

        }
        void printCriticalTasks();
        void completionTimeWithResources();
};

int main(){

    Task *taskArr;
    int totalTasks,x;
    cout << "Input the total number of tasks in this project\n";
    cin >> totalTasks;
    cout << "Input id of project\n";
    cin >> x;
    taskArr = new Task[totalTasks];
    
    Project p(taskArr,totalTasks,x);
    for(int i=0;i<totalTasks;i++){
        cout << "Task#" << i+1 << endl;
        taskArr[i].addTasks();
    }
    
    for(int i=0;i<totalTasks;i++){
        taskArr[i].findTime(taskArr,totalTasks);
    }
  
    for(int i=0;i<totalTasks;i++){
        taskArr[i].display();
    }
    
    p.completionTime();

    char ch;
    cout << "Would you like to change the duration of any of the tasks?\nPress y or n\n";
    cin >> ch;
    int id;
    if(ch=='y'){

        cout<<"Input task id for which you would like to change the duration\n";
        cin >> id;
        taskArr[id-1].set_nth_TaskDuration(taskArr,totalTasks,id);

    }
    


    return 0;
}