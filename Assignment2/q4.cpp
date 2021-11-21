#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
struct Card{
    char i;
    string suit;
    bool avail{true};
    void setChar(char x){
        i=x;
    }
    void setSuit(string suitX){
        suit = suitX;
    }
    void display(){
        cout << "Card: " << i << "\tSuit: " << suit;
        (avail==true)?cout << "\tAvailable\n":cout<<"\tNot available\n";
    }
};


struct Player{
    int id;
    int time; //duration of project
    Card* cardsInHand;
    bool dealer{false};
    bool trumpCaller{false};
    Player(){
        id=0;
        time=0;
        cardsInHand = new Card[13];
        dealer = false;
    }
};

Card* shuffleCards(Card* arr,int x){
    Card temp;
    int randomPos;
    srand(time(0));
    for(int i=0;i<x;i++){
        randomPos = i + (rand()%(x-i));
        temp = arr[i];
        arr[i]=arr[randomPos];
        arr[randomPos]=temp;
    }
    return arr;
}

int chooseDealer(){

    srand(time(0));
    return (rand()%4);

}

Card* Deal_and_Tumps(Player* playerArr,Card* mainCardArr){

    int randPos=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            
            if(mainCardArr[randPos].avail==true){
                mainCardArr[randPos].avail=false;
                playerArr[i].cardsInHand[j] = mainCardArr[randPos];
                randPos++;
            }
            
        }
    }
    Card* trump=new Card;
    int H,C,D,S;
    H=C=D=S=0;
    string x="";
    for(int i=0;i<4;i++){
        if(playerArr[i].trumpCaller==true){
            for(int j=0;j<5;j++){
                if(playerArr[i].cardsInHand[j].suit=="Hearts")
                    H++;
                else if(playerArr[i].cardsInHand[j].suit=="Clubs")
                    C++;
                else if(playerArr[i].cardsInHand[j].suit=="Diamonds")
                    D++;
                else if(playerArr[i].cardsInHand[j].suit=="Spades")
                    S++;
            }
            break;
        }
    }
    
    
    if(H>=C&&H>=D&&H>=S)
        trump->setSuit("Hearts");
    else if(C>=H&&C>=D&&C>=S)
        trump->setSuit("Clubs");
    else if(D>=H&&D>=C&&D>=S)
        trump->setSuit("Diamonds");
    else if(D>=H&&D>=C&&D>=S)
        trump->setSuit("Spades");
    else 
        cout << "No trump suit found\nPlay again\n";

    

    

    
    
    

    return trump;

}
void revealCards(Player* playerArr){
    for(int i=0;i<4;i++){
        cout << "\n\nFor player " << i+1 << endl << endl;
        for(int j=0;j<13;j++){
            cout << j+1 << ". ";
            playerArr[i].cardsInHand[j].display();

        }
    }
}
int main(){

    Player* playerList;
    playerList = new Player[4];
    Card* mainDeck;
    mainDeck = new Card[52];
    string suits[4]= {"Hearts","Clubs","Diamonds","Spades"};
    int counter=0;
    for(int i=0,j=0;i<52;i++){

        if(counter==13){
            counter=0;
            j++;
        }
        mainDeck[i].setSuit(suits[j]);
        switch(counter){
            case 0:
                mainDeck[i].setChar('a');
                break;
            case 1:
                mainDeck[i].setChar('2');
                break;
            case 2:
                mainDeck[i].setChar('3');
                break;
            case 3:
                mainDeck[i].setChar('4');
                break;
            case 4:
                mainDeck[i].setChar('5');
                break;
            case 5:
                mainDeck[i].setChar('6');
                break;
            case 6:
                mainDeck[i].setChar('7');
                break;
            case 7:
                mainDeck[i].setChar('8');
                break;
            case 8:
                mainDeck[i].setChar('9');
                break;
            case 9:
                mainDeck[i].setChar('t');
                break;
            case 10:
                mainDeck[i].setChar('j');
                break;
            case 11:
                mainDeck[i].setChar('q');
                break;
            case 12:
                mainDeck[i].setChar('k');
                break;
            default:
                break;
           
        }
        counter++;

    }
    char check;
    cout<< "\nWould you like to see the unshuffled deck now? Press y or n\n";
    cin >> check;
    if(check=='y'){
        for(int i=0;i<52;i++){
            mainDeck[i].display();
        }
    }
    
    shuffleCards(mainDeck,52);
    cout << "\nPost-shuffling:\n";
    cout<< "\nWould you like to see the shuffled deck now? Press y or n\n";
    cin >> check;
    if(check=='y'){
        for(int i=0;i<52;i++){
            mainDeck[i].display();
        }
    }
    
    int dealer=chooseDealer();
    int trumpCaller;
    if(dealer<3){
        trumpCaller=dealer+1;
    }
    else
        trumpCaller=0;

    cout << "\nDealer is Player " << dealer+1 <<endl;
    cout << "\nTrump Caller is Player " << dealer+2 <<endl;
    playerList[dealer].dealer=true;
    playerList[trumpCaller].trumpCaller=true;
    Card* trump = Deal_and_Tumps(playerList,mainDeck);
    cout << "\nTrump Suit is " << trump->suit << endl;
    cout<< "\nWould you like to reveal individual cards? Press y or n\n";
    cin >> check;
    if(check=='y'){
        cout << "\nRevealing individual player cards\n";
        revealCards(playerList);
    }
    srand(time(0));
    int x = (rand()%2);
    cout << "Team " << x+1 << " won!\n";
    cout << "Team " << !(x)+1 << " lost!\n";

    
    return 0;
}