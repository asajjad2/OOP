#include <iostream>
#include <ctime>
using namespace std;

struct Quote{
    
    char* quote;

    void getQuote(){
        
        quote = new char[400];
        cout << "Please input your weekly quote\n";
        cin.ignore();
        cin.getline(quote,400);

    }

    void displayQuote(){

        cout << quote << endl;

    }

    void editQuote(){

        cout << "Please re-input/edit your quote\n";
        cin.ignore();
        cin.getline(quote,400);

    }

};

struct Task
{

    char *instruction;
    tm *current;

    void addNewTask()
    {

        instruction = new char[250];
        cout << "Input new task\n";
        cin.ignore();
        cin.getline(instruction, 250);

        time_t now;
        now = time(NULL);
        current = localtime(&now);
    }
    void displayTask(){

        cout << instruction << endl;

    }

};

void displayTime(bool twentyfourHour)
{

    time_t now;
    now = time(NULL);
    if (twentyfourHour)
    {
        tm *localTime = localtime(&now);
        cout << localTime->tm_hour << ":";
        cout << localTime->tm_min << ":";
        cout << localTime->tm_sec << endl;
    }
    else
    {
        tm *localTime = localtime(&now);
        cout << (localTime->tm_hour) - 12 << ":";
        cout << localTime->tm_min << ":";
        cout << localTime->tm_sec << endl;
    }
}
void displayDate(bool dayMonth)
{
    time_t now;
    int month;
    now = time(NULL);
    if (dayMonth)
    {
        tm *localDate = localtime(&now);
        cout << localDate->tm_mday << "/";
        month = localDate->tm_mon;
        switch (month)
        {
        case 1:
            cout << "January/";
            break;
        case 2:
            cout << "February/";
            break;
        case 3:
            cout << "March/";
            break;
        case 4:
            cout << "April/";
            break;
        case 5:
            cout << "May/";
            break;
        case 6:
            cout << "June/";
            break;
        case 7:
            cout << "July/";
            break;
        case 8:
            cout << "August/";
            break;
        case 9:
            cout << "September/";
            break;
        case 10:
            cout << "October/";
            break;
        case 11:
            cout << "November/";
            break;
        case 12:
            cout << "December/";
            break;
        }
        cout << (localDate->tm_year) + 1900 << endl;
    }
    else
    {
        tm *localDate = localtime(&now);
        month = localDate->tm_mon;
        switch (month)
        {
        case 1:
            cout << "January/";
            break;
        case 2:
            cout << "February/";
            break;
        case 3:
            cout << "March/";
            break;
        case 4:
            cout << "April/";
            break;
        case 5:
            cout << "May/";
            break;
        case 6:
            cout << "June/";
            break;
        case 7:
            cout << "July/";
            break;
        case 8:
            cout << "August/";
            break;
        case 9:
            cout << "September/";
            break;
        case 10:
            cout << "October/";
            break;
        case 11:
            cout << "November/";
            break;
        case 12:
            cout << "December/";
            break;
        }
        cout << (localDate->tm_mday) << "/";
        cout << (localDate->tm_year) + 1900 << endl;
    }
}
bool changeTimeFormat()
{
    int x;
    cout << "Press 1 for 24 hour time format\nPress 2 for 12 hour time format\n";
    cin >> x;
    if (x == 1)
        return true;
    else if (x == 2)
        return false;
    else
    {
        cout << "Wrong option, try again!\n";
        return changeTimeFormat();
    }
}
bool changeDateFormat()
{
    int x;
    cout << "Press 1 for day/month/year format\nPress 2 for month/day/year format\n";
    cin >> x;
    if (x == 1)
        return true;
    else if (x == 2)
        return false;
    else
    {
        cout << "Wrong option, try again\n";
        return changeDateFormat();
    }
}

int main()
{

    bool twentyfourHour = true, dayMonth = true;
    int mainMenu = 1,currentTask=0,currentQuote=0,num;
    Task taskArr[10];
    Quote quoteArr[10];
    do
    {

        if (mainMenu != 1 && mainMenu != 2 && mainMenu != 3)
            cout << "You pressed a wrong button\n";

        cout << "~~Main Menu~~\n";
        cout << "Press 1 to display mirror\nPress 2 to enter add mode\nPress 3 to enter edit mode\nPress 4 to exit\n";
        cin >> mainMenu;
        int submenu;
        switch (mainMenu)
        {

        case 1:

            displayTime(twentyfourHour);
            displayDate(dayMonth);
            cout << "Tasks:\n";
            for(int i=0;i<currentTask;i++){
                cout << i+1 << ". ";
                taskArr[i].displayTask();
            }
            cout << "Your weekly quotes:\n";
            for(int i=0;i<currentQuote;i++){
                cout << i+1 << ". ";
                quoteArr[i].displayQuote();
            }
            break;

        case 2:

            submenu = mainMenu;
            while (submenu != 3)
            {

                if (submenu != 1 && submenu != 2 && submenu != 3)
                    cout << "You pressed a wrong button\n";

                cout << "~~Add Menu~~\n";
                cout << "Press 1 to add new weekly quote\nPress 2 to add a new task\nPress 3 to exit add menu\n";
                cin >> submenu;
                switch (submenu)
                {
                case 1:

                    quoteArr[currentQuote].getQuote();
                    currentQuote++;
                    break;

                case 2:

                    taskArr[currentTask].addNewTask();
                    currentTask++;
                    break;

                default:
                    break;
                }
            }
            break;

        case 3:

            submenu = mainMenu;
            while (submenu != 5)
            {

                if (submenu != 1 && submenu != 2 && submenu != 3 && submenu != 4 && submenu != 5)
                    cout << "You pressed a wrong button\n";
                    
                cout << "~~Edit Menu~~\n";
                cout << "Press 1 to edit date display format\nPress 2 to edit your weekly quote\nPress 3 to edit time display format\nPress 4 to delete a task\nPress 5 to exit edit menu\n";
                cin >> submenu;
                switch (submenu)
                {
                case 1:
                    dayMonth = changeDateFormat();
                    break;
                case 2:

                    cout << "Please input the number of quote you'd like to edit out\n";
                    cin >> num;
                    quoteArr[num-1].editQuote();
                    break;

                case 3:
                    twentyfourHour = changeTimeFormat();
                    break;
                case 4:

                    cout << "Input the number of task you would like to delete\n";
                    cin >> num;
                    for(int i=num-1;i<currentTask;i++){
                        
                            taskArr[i]=taskArr[i+1];

                    }
                    currentTask--;
                    break;

                default:
                    break;
                }
            }
            break;

        default:
            break;
        }

    } while (mainMenu != 4);


    for(int i=0;i<currentTask;i++){
        delete[] taskArr[i].instruction;
    }
    for(int i=0;i<currentQuote;i++){
        delete[] quoteArr[i].quote;
    }
    return 0;
}