#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;



class Player{

private:
    int id;
    char* name;
    char* type; 
    int points; 
    bool availability; 
public:
    void setID(int x){

        id = x;

    }
    void setName(char* x){

        name = x;

    }
    void setType(char* x){

        type = x;

    }
    void setPoints(int x){

        points +=x;

    }
    void setAvailability(bool x){

        availability = x;

    }
    int getID() const{

        return id;

    }
    char* getName() const{

        return name;

    }
    char* getType() const{

        return type;

    }
    double getPoints() const{

        return points;

    }
    bool getAvailability() const{

        return availability;

    }
    void display(){
        cout << id << "   " << name << "   " << type << "   " << points << "      ";
        (availability==1)?(cout << "Available\n"):(cout << "Not available\n");
    }
    void LeaderboardDisplay(){
        cout << id << "   " << name << "   " << type << "   Points::" << points << endl;
    }


};

class Team{

private:

    const char* teamName;
    int teamRank;
    Player* teamPlayers;
    int strategy; //0 for defense, 1 for attack
    bool matchState; //becomes true when has matched against all other teams
    bool winState; //true when victory
    int score;

public:

    Team(){
        teamName=NULL;
        teamPlayers=NULL;
        strategy=0;
        teamRank=0;
        matchState=false;
        winState=false;
    }

    void incrementScore(){
        score++;
    }
    int getScore() const{
        return score;
    }

    void setTeamName(const char* x){

        teamName=x;

    }

    int getRank() const {

        return teamRank;

    }

    void setRank(int x){

        teamRank=x;

    }

    void setStrategy(int x){

        strategy=x;

    }

    int getStrategy() const {

        return strategy;

    }

    void display(){

        cout << teamName << " Rank::" << teamRank << " " << "Score::" << score << " ";
        (strategy==1)?(cout << "Strategy::Attacking\n"):(cout << "Strategy::Defensive\n");
        

    }
    void showPlayers(){
        for(int i=0;i<3;i++){
            cout << teamPlayers[i].getName() << endl;
        }  
    }

    Player* getPlayers(){
        return teamPlayers;
    }

    void setPlayers(Player* x){

        teamPlayers=x;

    }

    const char* getTeamName(){
        return teamName;
    }

    void setMatchState(bool x){
        matchState=x;
    }

    bool getMatchState() const{

        return matchState;
    }

    void setWinState(bool x){
        winState=x;
    }

    bool getWinState() const{

        return winState;
    }


};

class Match{
int Match_No;
Team homeTeam;
Team awayTeam;
public:
    int getMatchNo() const{
        return Match_No;
    }
    void setMatchNo(int x){
        Match_No=x;
    }
    Team getHomeTeam() const{
        return homeTeam;
    }
    void setHomeTeam(Team x){
        homeTeam=x;
    }
    Team getAwayTeam() const{
        return awayTeam;
    }
    void setAwayTeam(Team x){
        awayTeam=x;
    }
};

Player* addPlayers(Player* playerArr)
{
        bool avail;
        char* name;
        char* type;
        ifstream in_file;
        in_file.open("players.txt");
        for(int i=0;i<12;i++)
        {
            name = new char[25];
            type = new char[10];
            in_file >> name >> type;
            playerArr[i].setName(name);
            playerArr[i].setType(type);
            playerArr[i].setID(i+1);
            playerArr[i].setAvailability(true);
        }
        return playerArr; 
    
}
Player* returnPlayers(Player* playerArr, Player* sortedPlayersArr){

    const char* d="defensive";
    const char* a="attacking";
    for(int i=0,j=0;i<12;i++){

        if(*(playerArr[i].getType())=='d'){
            sortedPlayersArr[j]=playerArr[i];
            j++;
        }

    }
    for(int i=0,j=6;i<12;i++){

        if(*(playerArr[i].getType())=='a'){
            sortedPlayersArr[j]=playerArr[i];
            j++;
        }

    }
    /*  for(int a=0;a<12;a++){
        cout << playerArr[a].getID() << " " << playerArr[a].getName() << " " << playerArr[a].getType() << " " << playerArr[a].getPoints() << " " << playerArr[a].getAvailability() << endl;
    }
    for(int a=0;a<12;a++){
        cout << sortedPlayersArr[a].getID() << " " << sortedPlayersArr[a].getName() << " " << sortedPlayersArr[a].getType() << " " << sortedPlayersArr[a].getPoints() << sortedPlayersArr[a].getAvailability() << endl;
    } */
    return sortedPlayersArr;

}

Team* assignRanks(Team* teamArr){

    for(int i=0;i<4;i++){

        srand(time(0));
        int random;
        do{

            random = 1+(rand()%4);

        }while(random==teamArr[0].getRank()||random==teamArr[1].getRank()||random==teamArr[2].getRank()||random==teamArr[3].getRank());

        teamArr[i].setRank(random);

    }
    
    return teamArr;

}

Team* assignWin(Team* teamArr,int home, int opp){

    /*teamArr[home].setWinState(rand()%2);
    int random;
    while(random==teamArr[home].getWinState()){
        random=(rand()%2);
    }
    teamArr[opp].setWinState(randomm); */
    int random;
    int x =rand()%2;
    random =x;
    while(random==x){
        random=rand()%2;
    }
    teamArr[home].setWinState(x);
    teamArr[opp].setWinState(random);
    /* bool random;
    for(int i=0;i<2;i++){

        
        do{

            random = rand()%1;

        }while((teamArr[0].getWinState()==random)||(teamArr[1].getWinState()==random));

        teamArr[i].setWinState(random);

    } */

    return teamArr;

}

void bestPlayersInMatch(Team* teamArr, int win, int lose, Player* winners, Player* losers){

    cout << "Best player for " << teamArr[win].getTeamName() << " ";
    int highest=winners[0].getPoints();
    for(int i=1;i<3;i++){
        if(winners[i].getPoints()>highest)
            highest=winners[i].getPoints();
    }
    for(int i=0;i<3;i++){
        if(highest==winners[i].getPoints()){
            cout << winners[i].getName() << endl;
            break;
        }
    }

    cout << "Best player for " << teamArr[lose].getTeamName() << " ";
    highest = losers[0].getPoints();
    for(int i=1;i<3;i++){
        if(losers[i].getPoints()>highest)
            highest=losers[i].getPoints();
    }
    for(int i=0;i<3;i++){
        if(highest==losers[i].getPoints()){
            cout << losers[i].getName() << endl;
            break;
        }
    }
    cout << endl;
}

Team* updatePlayerPoints(Team* teamArr, int win, int lose){


    Player* winPlayers = teamArr[win].getPlayers();
    Player* losePlayers = teamArr[lose].getPlayers();
    //cout << "ID" << "  " << "Name\t     " << "Strategy    " << "Points " << endl;
    for(int i=0;i<3;i++){
        winPlayers[i].setPoints(10+(rand()%11));    
    }
    cout << endl;
    srand(time(0));
;
    //cout << "ID" << "  " << "Name\t     " << "Strategy    " << "Points " << endl;
    for(int i=0;i<3;i++){
        losePlayers[i].setPoints(5+(rand()%6));      
    }
    srand(time(0));
    teamArr[win].setPlayers(winPlayers);
    teamArr[lose].setPlayers(losePlayers);
    cout << "Press 1 to show match stats\n";
    int test;
    cin >> test;
    if(test==1){
        cout << "~~~~~~~~~~~~~~~~~~~~" << teamArr[win].getTeamName() << "~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        for(int i=0;i<3;i++){
            winPlayers[i].display();
        }
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~" << teamArr[lose].getTeamName() << "~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        for(int i=0;i<3;i++){
            losePlayers[i].display();
        }
        cout << endl;
        bestPlayersInMatch(teamArr,win,lose,winPlayers,losePlayers);
    }
    
    

    return teamArr;
}

Team* sortTeams(Team* teamArr){

    Team temp;
    for(int i=0;i<3;i++){

        for(int i=0;i<3;i++){

            if(teamArr[i].getRank()<teamArr[i+1].getRank()){

                temp=teamArr[i];
                teamArr[i]=teamArr[i+1];
                teamArr[i+1]=temp;

            }

        }
    }
    

    return teamArr;

}

Team* playerSelection(Team* teamArr, Player* playerArr, Player* sortedPlayerArr){

    for(int i=0;i<4;i++){
        Player* subArr;
        int counter=0;
        subArr=new Player[3];
        for(int m=0;m<3;m++){
            cout << "Selection for team " << i+1 << endl;
            teamArr[i].display();
            cout << "Player " << counter+1 << endl;
            if(teamArr[i].getStrategy()==0){
                cout << "This is a defensive team\nThey would prefer to choose 2 defensive and 1 offensive players\nHere is a sorted list of available players\n";
                for(int j=0;j<12;j++){
                    if(sortedPlayerArr[j].getAvailability()==true)
                        sortedPlayerArr[j].display();
                }
                int id;
                bool available=false,correct=false;
                while(correct!=true){

                    while(available!=true){
                        cout << "Input the ID for a player you would like to choose for team " << teamArr[i].getTeamName() << endl;
                        cin >> id;
                        for(int j=0;j<12;j++){

                            if(id==playerArr[j].getID()){
                                correct=true;
                                if(playerArr[j].getAvailability()==true){
                                    available=true;
                                    cout << "Available\n";
                                    playerArr[j].setAvailability(false);
                                    for(int k=0;k<12;k++){
                                        if(id==sortedPlayerArr[k].getID()){
                                            sortedPlayerArr[k].setAvailability(false);
                                            break;
                                        }
                                    }
                                
                                    break;
                                }
                            
                            }
                        }
                        if(!correct){
                            cout << "Incorrect ID\n";
                        }
                        else if(!available){
                            cout << "Player not available\n";
                        }
                    }
                

                }
                for(int j=0;j<12;j++){
                    if(id==playerArr[j].getID()){
                        subArr[counter]=playerArr[j];
                        //cout << playerArr[j].getName() << endl;
                        //cout << subArr[counter].getName() << endl;
                        counter++;
                        break;
                    }
                }
                
            

            
            
            

            }
            else{
                cout << "This is an offensive team\nThey would prefer to choose 2 offensive and 1 defensive players\nHere is a sorted list of available players\n";
                for(int j=0;j<12;j++){
                    if(sortedPlayerArr[j].getAvailability()==true)
                        sortedPlayerArr[j].display();
                }
                int id;
                bool available=false,correct=false;
                while(correct!=true){

                    while(available!=true){
                        cout << "Input the ID for a player you would like to choose for team " << teamArr[i].getTeamName() << endl;
                        cin >> id;
                        for(int j=0;j<12;j++){
                            if(id==playerArr[j].getID()){
                                correct=true;
                                if(playerArr[j].getAvailability()==true){
                                    available=true;
                                    cout << "Available\n";
                                    playerArr[j].setAvailability(false);
                                    for(int k=0;k<12;k++){
                                        if(id==sortedPlayerArr[k].getID()){
                                            sortedPlayerArr[k].setAvailability(false);
                                            break;
                                        }
                                    }
                                
                                    break;
                                }
                            
                            }
                        }
                        if(!correct){
                            cout << "Incorrect ID\n";
                        }
                        else if(!available){
                            cout << "Player not available\n";
                        }
                    }
                

                }
                for(int j=0;j<12;j++){
                    if(id==playerArr[j].getID()){
                        //cout << playerArr[j].getName() << endl;
                        subArr[counter]=playerArr[j];
                        //cout << subArr[counter].getName() << endl;
                        counter++;
                        break;
                    }
                }
                
            }
            
             
        }
            
            teamArr[i].setPlayers(subArr);
            cout << "Final Team Members\n";
            for(int j=0;j<3;j++){
                
                cout << subArr[j].getName() << endl;
            } 
        }
        
        return teamArr;


}

Team* generateMatchStats(Player* playerArr, Player* sortedPlayerArr, Team* teamArr){

    Match matchHistory[12];
    int counter=0;
    for(int h=0;h<2;h++){
        for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){
            
            if(i==j)
                continue;
            else{

                if(teamArr[j].getMatchState()==false){
                    matchHistory[counter].setMatchNo(counter+1);
                    matchHistory[counter].setHomeTeam(teamArr[i]);
                    matchHistory[counter].setAwayTeam(teamArr[j]);
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Match #" << counter+1 << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << "~~~~~~~~~~~~~~~" <<teamArr[i].getTeamName() << " vs " << teamArr[j].getTeamName() << "~~~~~~~~~~~~~~~" << endl << endl;
                    counter++;
                    teamArr=assignWin(teamArr,i,j);
                    cout << "==> " << teamArr[i].getTeamName(); 
                    (teamArr[i].getWinState()==1)?(cout << " emerged victorious\n"):(cout<<" faced defeat\n");
                    cout << "==> " << teamArr[j].getTeamName();
                    (teamArr[j].getWinState()==1)?(cout << " emerged victorious\n"):(cout<<" faced defeat\n");  
                    cout << endl;
                    if((teamArr[i].getWinState()==true)&&(teamArr[j].getWinState()==false)){
                        teamArr=updatePlayerPoints(teamArr,i,j);
                        teamArr[i].incrementScore();
                    }
                    else if((teamArr[i].getWinState()==false)&&(teamArr[j].getWinState()==true)){
                        teamArr=updatePlayerPoints(teamArr,j,i);
                        teamArr[j].incrementScore();
                    }
                }
                else
                    continue;
            }

            
        }
        teamArr[i].setMatchState(true);

    }
        for(int i=0;i<4;i++){
            teamArr[i].setMatchState(false);
        }
    }
    

    return teamArr;
}





Team* teamSelection(Team* teamArr){


//setname
    const char* name1="Sweet Shots";
    const char* name2="Set2Win";
    const char* name3="Match Points";
    const char* name4="Scared Hitless";

    teamArr[0].setTeamName(name1);
    teamArr[1].setTeamName(name2);
    teamArr[2].setTeamName(name3);
    teamArr[3].setTeamName(name4);

    teamArr=assignRanks(teamArr);

    for(int i=0;i<4;i++){

        teamArr[i].setStrategy(rand()%2);

    }


    return teamArr;


}

void printLeaderBoard(Player* playerArr){

    Player x;

    for(int i=0;i<12;i++){
        for(int j=i+1;j<12;j++){
        if(playerArr[i].getPoints()<playerArr[j].getPoints()){
            x=playerArr[i];
            playerArr[i]=playerArr[j];
            playerArr[j]=x;
        }
    }}


    
    cout << "~~~~~~~~~~~~~~~~~~~~LeaderBoard~~~~~~~~~~~~~~~~~~~~~\n\n";
    for(int i=0;i<12;i++){
        playerArr[i].LeaderboardDisplay();
        cout << endl;
    }


}

void printTeamRanks(Team* teamArr){

    Team x;

    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(teamArr[i].getScore()<teamArr[j].getScore()){
                x=teamArr[i];
                teamArr[i]=teamArr[j];
                teamArr[j]=x;
            }
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~Team Rankings~~~~~~~~~~~~~~~~~~~~~\n\n";
    for(int j=0;j<4;j++){
        teamArr[j].setRank(j+1);
        teamArr[j].display();
        cout << endl;
    }
    

}


int main(){

    Player* playerList = new Player[12];
    Player* sortedPlayers = new Player[12];
    Team* teamList = new Team[4];
    playerList = addPlayers(playerList);
    sortedPlayers = returnPlayers(playerList,sortedPlayers);
    /* for(int a=0;a<12;a++){
        cout << playerList[a].getID() << " " << playerList[a].getName() << " " << playerList[a].getType() << " " << playerList[a].getPoints() << " " << playerList[a].getAvailability() << endl;
    } */
    teamList = teamSelection(teamList);
    teamList = playerSelection(teamList, playerList, sortedPlayers);
    for(int i=0;i<4;i++){
        teamList[i].display();
    }
    /* for (int i=0;i<4;i++){
        cout << "\t" << teamList[i].getTeamName() << endl;
        teamList[i].showPlayers();
    }  */
    
    teamList=generateMatchStats(playerList,sortedPlayers,teamList);
    int counter=0;
    int j=0;
    for(int i=0;i<4;i++){
        Player* subarr;
        subarr=teamList[i].getPlayers();
        for(int counter=0;counter<3;counter++){
            playerList[j]=subarr[counter];
            j++;
        }
    
    }

    printLeaderBoard(playerList);
    printTeamRanks(teamList);
    return 0;

}