#include <iostream>
#include <fstream>
using namespace std;

struct Sales_Person;
struct Salary;
struct Customer;
struct Book;
struct Address;


struct Book{
int id;
char *type;
char *bookName;
char *authorName;
double price;
int remaining;

void setBookInfo(){ //fills the book info for books added by the user
    cout << "Input book id\n";
    cin >> id;

    type = new char[25];
    cin.ignore(10,'\n');
    cout << "Input book type, following book types exist: history, science , and adventure\n";
    cin.getline(type,25);

    bookName = new char[50];
    cout << "Input book name\n";
    cin.getline(bookName,50);

    authorName = new char[50];
    cout << "Input book author\n";
    cin.getline(authorName,50);

    cout << "Input book price\n";
    cin >> price;
    cout << "Input quantity of these books\n";
    cin >> remaining;
}
Book* fillBookInfo(Book*inv,int totalBooks){ //fills the book info for customer book arrays
        for(int i=0;i<totalBooks;i++){
            if(id==inv[i].id){

                type=inv[i].type;
                bookName=inv[i].bookName;
                authorName=inv[i].authorName;
                price=inv[i].price;
                inv[i].remaining--;

            }
        }
        return inv;
    }
};
Book* set10(Book* bookArr)
{
        ifstream in_file;
        in_file.open("library.txt");
        for(int i=0;i<10;i++)
        {
            bookArr[i].type = new char [50];
            bookArr[i].bookName = new char [50];
            bookArr[i].authorName = new char [50];
            in_file >> bookArr[i].type >> bookArr[i].bookName >> bookArr[i].authorName;
        }
        return bookArr;
    
}

struct Address{
    int House;
    int street;
    char* town;
    char* city;
    void getAddressInfo(){
        cout << "Input House number\n";
        cin >> House;

        cout << "Input street number\n";
        cin >> street;

        town = new char [20];
        cin.ignore(10,'\n');
        cout << "Input town name\n";
        cin.getline(town,20);

        city = new char [15];
        cout << "Input city name\n";
        cin.getline(city,15);
    }
};

struct Salary{
double fixedSalary; 
double comission; 
void setSalary(double Sales){
    fixedSalary=15000;
    comission= 0.2*Sales;
}
};

struct Customer{
    int cust_No;
    char *cust_Name; 
    Address cust_Address; 
    Book bk; 
    void getCustomerInfo(){
        cout << "Please input customer number" << endl;
        cin >> cust_No;

        cust_Name= new char[25];
        cout << "Input name\n";
        cin.ignore(10,'\n');
        cin.getline(cust_Name,25);
        cust_Address.getAddressInfo();
        cout << "Input id of the book bought\n";
        cin >> bk.id;
    }   
};

struct Sales_Person{
    int emp_ID;
    char *emp_Name; 
    double Sales;
    int customers;
    Customer *emp_Customer_Array; 
    Salary emp_sal; 
    
    
        
    void setStaffInfo(){
    
        cout << "Input ID\n";
        cin >> emp_ID;
        
        emp_Name = new char[25];
        cin.ignore(10,'\n');
        cout << "Input name\n";
        //cin >> emp_Name;
        cin.get(emp_Name,25, '\n');
        cin.ignore(10,'\n');
        
        cout << "Input number of customers for this sales person\n";
        cin >> customers;
        emp_Customer_Array= new Customer[customers];
    
        for(int i=0;i<customers;i++){
            cout << "Customer " << i+1 << endl;
            emp_Customer_Array[i].getCustomerInfo(); 
        }
    
    }
        
    double totalSalesBySalesPerson(){
    
        double amount=0;
        for(int i=0;i<customers;i++){
            amount+=emp_Customer_Array[i].bk.price;
        }
        Sales=amount;
        return amount;
    
    }
        
};


double totalSales(Sales_Person *arr,int num){
    double amount=0;
    for(int i=0; i<num; i++){
        amount+=arr[i].Sales;
    }
    return amount;
}



Sales_Person * topSalesPerson(Sales_Person *arr,int num){

    Sales_Person temp;
    
    for(int i=0;i<num-1;i++){
        for(int i=0; i<num-1; i++){
            if(arr[i].Sales<arr[i+1].Sales){
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    
    for(int i=0;i<num;i++){
        cout << arr[i].emp_Name << ": " << arr[i].Sales << "Rs" << endl;
    }
    return arr;
}




double totalSalary(Sales_Person *arr,int num){
    double totalSalaries=0;
    for(int i=0; i<num; i++){
        totalSalaries+=(arr[i].emp_sal.fixedSalary+arr[i].emp_sal.comission);
    }
    return totalSalaries;
}
void booksInventory(Book *bkArr, int bkSize){ //calculate and display remaining books
    
    for(int i=0; i<bkSize; i++){
        cout << "Name: " << bkArr[i].bookName << " ID: " << bkArr[i].id << " In inventory: " << bkArr[i].remaining << endl;
    }
}

void booksInventoryByType(Book *bkArr, int bkSize){

    cout << "Please input the type of book whose inventory you wish to see\n";
    Book temp;
    temp.type = new char[50];
    cin.ignore(10,'\n');
    cin.getline(temp.type,50);
    cout << temp.type << " books:" << endl; 
    for(int i=0; i<bkSize; i++){
        
        if(*(bkArr[i].type)==*(temp.type)){
            cout << bkArr[i].bookName << " ID:" << bkArr[i].id << " In inventory: " << bkArr[i].remaining << endl;
        }
        
    }
    return;
    
}



int main(){

    int numSalesPeople,numBooks;
    
    cout << "10 Books already exist in inventory, if you wish to add more, please input number of Books\n";
    cin >> numBooks;
    numBooks+=10;
    Book* Inventory = new Book[numBooks];
    //setting book info for the first 10 books
    Inventory=set10(Inventory);
        Inventory[0].id=1;
        Inventory[0].remaining=10;
        Inventory[0].price=500;
        Inventory[1].id=2;
        Inventory[1].remaining=8;
        Inventory[1].price=350;
        Inventory[2].id=3;
        Inventory[2].remaining=5;
        Inventory[2].price=350;
        Inventory[3].id=4;
        Inventory[3].remaining=14;
        Inventory[3].price=700;
        Inventory[4].id=5;
        Inventory[4].remaining=7;
        Inventory[4].price=700;
        Inventory[5].id = 6;
        Inventory[5].remaining = 9;
        Inventory[5].price = 900;
        Inventory[6].id = 7;
        Inventory[6].remaining = 9;
        Inventory[6].price = 900;
        Inventory[7].id = 8;
        Inventory[7].remaining = 20;
        Inventory[7].price = 650;
        Inventory[8].id = 9;
        Inventory[8].remaining = 4;
        Inventory[8].price = 650;
        Inventory[9].id = 10;
        Inventory[9].remaining = 7;
        Inventory[9].price = 900;


        for (int i = 10; i < numBooks; i++)
        {
            cout << "Book " << i + 1 << endl;
            Inventory[i].setBookInfo();
        }
        cout << "Please input number of Sales People\n";
        cin >> numSalesPeople;

        Sales_Person* SalesArr = new Sales_Person[numSalesPeople];
        for(int i=0;i<numSalesPeople;i++){
            cout << "Sales person " << i+1 << endl;
            SalesArr[i].setStaffInfo();
        }
        for (int i=0;i<numSalesPeople;i++){
            for(int j=0;j<SalesArr[i].customers;j++){
                Inventory=SalesArr[i].emp_Customer_Array[j].bk.fillBookInfo(Inventory,numBooks);
            }
        }
        for (int i=0;i<numSalesPeople;i++){
            double temp;
            temp=SalesArr[i].totalSalesBySalesPerson();
        }
        for (int i=0;i<numSalesPeople;i++){
            SalesArr[i].emp_sal.setSalary(SalesArr[i].Sales);
        }

    int menu=0;
    while(menu==0){

        cout << "Press 0 to see menu otherwise program exits\n";
        cin >> menu;
        int submenu=0;
        if(menu==0){
            
            cout << "Press 1 to display total Sales\n";
            cout << "Press 2 to display the Sales of a specific employee\n";
            cout << "Press 3 to get a sales-vise sorted list of sales people\n";
            cout << "Press 4 to get the commission of a specific employee\n";
            cout << "Press 5 to get the total Salary owner has to pay\n";
            cout << "Press 6 to check inventory\n";
            cout << "Press 7 to check inventory by book type\n";
            cout << "You may press now\n";
            cin >> submenu;
            switch(submenu){
                case 1:
                    cout << "Total Sales are: " << totalSales(SalesArr,numSalesPeople) << endl;
                    break;
                case 2:
                    int id;
                    cout << "Input id of employee whose sales you wish to see\n";
                    cin >> id;
                    for(int i=0;i<numSalesPeople;i++){
                        if(id==SalesArr[i].emp_ID){
                            cout << "Sales made by" << SalesArr[i].emp_Name << "\nID:" << SalesArr[i].emp_ID << "\tSales:" << SalesArr[i].totalSalesBySalesPerson() << "Rs." << endl;
                        }
                    }
                    break;
                case 3:
                    SalesArr= topSalesPerson(SalesArr,numSalesPeople);
                    break;
                case 4:
                    cout << "Input id of employee whose commission you wish to see\n";
                    cin >> id;
                    for(int i=0;i<numSalesPeople;i++){
                        if(id==SalesArr[i].emp_ID){
                            cout << "Commission made by\n" << SalesArr[i].emp_Name << "\n" << "Commission:" <<  SalesArr[i].emp_sal.comission << "Rs." << endl;
                        }
                    }
                    break;
                case 5:
                    cout << "The owner has to pay:" << totalSalary(SalesArr,numSalesPeople) << endl; 
                    break;
                case 6:
                    booksInventory(Inventory,numBooks);
                    break;
                case 7:
                    booksInventoryByType(Inventory,numBooks);
                    break;
                default:
                    break;
            }
        }

        

    }



    
    

    return 0;
}