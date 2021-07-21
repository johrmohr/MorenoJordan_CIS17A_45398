/* 
 * File:   main.cpp
 * Author: Jordan Moreno
 * Created on July 15, 2021 4:58pm
 * Purpose:  Blackjack game
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>     //Strings
#include <fstream>    //File I/O
#include <iomanip>    //I/O Manipulators
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
#define SIZE 52 //Sets size of shoe to the 52 cards in a deck

//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
struct Players{
    string name; //Name of players
    int balance; //Player's starting balance
};

enum result{
    LOSE, WIN, PUSH, BLCKJCK
};

enum Face{
    ACE=1, JACK=11, QUEEN, KING
};

void create(int shoe[],int);      //Create shoe
void shuffle(int shoe[],int,int); //Shuffle shoe
int readBal(char binName[]); //Reads player balance from binary file
string rName(char filName[]); //Reads player name from text file
int Game(int shoe[], int &); //Initializes game loop
int gtCount(int hand[], int); //Gets the count (card #'s added up)
char getChar(int); //Gets card letter for face cards (J,Q,K,A,T=10)
void PriHand(int hand[], int); //Prints the users hand

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set the random number seed
    srand(time(NULL));
    
    //Declare variables
    int nDecks=4;          //Number of decks
    int shoe[SIZE*nDecks]; //Shoe array with 4 decks
    int deck_pl=0; //Place in deck, starts at 0
    int wager; //Player wager input
    int *wageptr; //Pointer for wager variable
    Players *info = new Players[2]; //Structure pointer arrays
    char binName[]="Balance.bin";   //Char Array Name for binary file balance
    char filName[]="Names.txt";     //Char Array Name for text file name
    
    //Read player name and balance from functions
    info[0].balance=readBal(binName);  //Assign balance to structure
    info[0].name=rName(filName);       //Assign name to structure
    
    //Creates and then shuffles the shoe array
    create(shoe, nDecks); 
    shuffle(shoe, nDecks, 50); 
    
    cout << info[0].name << "'s balance begins at $" << info[0].balance << endl;
    while(1){
        // User keeps playing until they wager $0
        cout << "Enter Wager (0 to quit): $";
        cin >> wager;
        if(wager > info[0].balance){
            cout << endl << "Insufficience funds. Current Balance: "
                 << info[0].balance << endl << endl;
            continue;
        } 
        else if(wager <= 0){ //Ends game if user wages 0
            cout << "Thanks for playing!";
            exit(0);
        }
        int result = Game(shoe, deck_pl); //Result from Play function to int
        switch(result){
            // DEALER WINS, user loses their wager
            case 0: 
            info[0].balance -= wager;
            break;
            // USER WINS, keep wager and add wager to existing balance
            case 1: 
            info[0].balance += wager;
            break;
            // PUSH, wager returned to user because of tie, nothing happens
            case 2: 
            break;
            //USER WON BLACKJACK (21), keep wager and add 1.5x wager to balance
            case 3: 
            info[0].balance += wager * 1.5;
            break;
        }
        
        //Show player their balance
        cout << endl << info[0].name << "'s BALANCE: $" << info[0].balance
             << endl;
        if (info[0].balance <= 0){
            cout << "No balance left: GAME OVER" << endl;
            exit(0);
        }
        
        // If more than 3/4 of the shoe has been played, a reshuffle occurs
        if(deck_pl > nDecks*52*.75){
            cout << endl << endl
                 << "==============================" << endl << endl
                 << "RESHUFFLING" << endl << endl
                 << "==============================" << endl << endl;
            create(shoe, nDecks);
            shuffle(shoe, nDecks, 50);
            deck_pl=0; //Reinitialize place in deck at 0
        }
    }
    
    return 0;
}

int readBal(char binName[]){
    //Input balance for the player
    ifstream binFile(binName, ios::binary); //Binary file
    //Integer to access data from binary file
    int a;
    binFile.read(reinterpret_cast<char*>(&a), sizeof(a)); //Read data
    binFile.close();
    Players temp; //Temporary structure variable
    temp.balance = a;
    return temp.balance;
}

string rName(char filName[]){
    //Input name for the player
    string b;
    ifstream File(filName); //Text file
    File>>b;
    File.close();
    return b;
}

//Creates a non-randomized shoe array
void create(int shoe[], int nDecks){
    for(int i=0; i<nDecks; i++){
        for(int j=0; j<4; j++){
            for(int k=1; k<=13; k++){
                int index = (i*SIZE) + (j*13) + k - 1;
                shoe[index] = k;
            }
        }
    }
}

//Shuffles the shoe array nShuffl times
void shuffle(int shoe[], int nDecks, int nShuffl){
    for(int i=0; i<nShuffl; i++){
        for(int j=0; j<(SIZE*nDecks); j++){
            int index = rand() % (SIZE*nDecks);
            int temp = shoe[index];
            shoe[index] = shoe[j];
            shoe[j] = temp;
        }
    }
}

// GAME LOOP
int Game(int shoe[], int &deckPlc){
    int dealhnd[20], //Dealer array size
        userhnd[20], //User array size
        dealsiz = 2, //Dealer size
        usrsize = 2, //User size
        dealcnt = 0, //Dealer count
        usercnt = 0; //User count

    userhnd[0] = shoe[deckPlc++]; //First card for user
    dealhnd[0] = shoe[deckPlc++]; //Prevents Dealer first card from being 0
    userhnd[1] = shoe[deckPlc++]; //Second card for user
    dealhnd[1] = shoe[deckPlc++]; //Changes first card for dealer

    dealcnt = gtCount(dealhnd, dealsiz); //Gets dealer count
    usercnt = gtCount(userhnd, usrsize); //Gets user count

    cout << "================================" << endl
         << endl
         << "YOUR HAND: ";
    PriHand(userhnd, usrsize); //Print your hand, 2 cards
    cout << "COUNT: " << usercnt << endl
         << "DEALER SHOWS: "
         << getChar(dealhnd[1]) //Gets one card for dealer 
         << endl;

    bool loop = true;
    while(loop){
        char move;
        cout << "\nType your move\nHit: (h), Stand: (s) ";
        cout << "\n\n";
        cin >> move;
        cout << "\n\n";
        switch(move){
            
            //If user chooses to hit 'h'
            case 'h': 
                userhnd[usrsize++] = shoe[deckPlc++];
                usercnt = gtCount(userhnd, usrsize);
                
                // User gets 21/blackjack
                if(usercnt == 21){ 
                    loop = false;
                    break;
                }
                cout << "YOUR HAND: ";
                PriHand(userhnd, usrsize);
                cout << "COUNT: " << usercnt << endl;
                
                // USER BUSTS, count>21
                if(usercnt > 21){ 
                    cout << "BUSTED: YOU LOST\n";
                    return 0;
                }
                
                cout << "DEALER SHOWS: ";
                cout << getChar(dealhnd[1]);
                cout << endl;
                break;
                
            //If user chooses to stand 's'
            case 's':
                loop = false;
                break;
            //loop is still true if user inputs something other than 'h' or 's'
            default:
                cout << "Please enter 'h' for hit or 's' for stand.\n\n";
                continue;
        }
    }
    
    //Gives dealer cards until the count is at least greater than 17
    loop = true;
    while(loop){
        if(dealcnt < 17){
            dealhnd[dealsiz++] = shoe[deckPlc++];
            dealcnt = gtCount(dealhnd, dealsiz);
        }
        else{
            loop = false;
        }
    }

    cout << "YOUR HAND: ";
    PriHand(userhnd, usrsize);
    cout << "COUNT: " << usercnt << endl;
    cout << "DEALER HAND: ";
    PriHand(dealhnd, dealsiz); 
    cout << "DEALER COUNT: " << dealcnt << endl;

    //Game ties, PUSH
    if(dealcnt == usercnt){
        cout << "PUSH. No wager lost." << endl;
        return PUSH;
    }
    //Dealer busts and User wins blackjack
    else if(usercnt == 21 && dealcnt > 21){
        cout << "DEALER BUSTED, YOU WON, BLACKJACK!" << endl;
        return BLCKJCK;
    }
    //User wins blackjack over dealer
    else if(usercnt == 21){
        cout << "YOU WON, BLACKJACK!" << endl;
        return BLCKJCK;
    }
    //Dealer busts, user wins
    else if(dealcnt > 21){
        cout << "DEALER BUSTED: YOU WON!" << endl;
        return WIN;
    }
    //User wins over dealer
    else if(usercnt > dealcnt){
        cout << "YOU WON!" << endl;
        return LOSE;
    }
    //Dealer wins over user
    else if(dealcnt > usercnt){
        cout << "YOU LOST!" << endl;
        return LOSE;
    }
    return LOSE;
}

// Gets count of a hand
int gtCount(int hand[], int size){ 
    int count = 0; //Count, added cards together
    int nAces = 0; //number of Aces
    for(int i=0; i<size; i++){
        int card = hand[i];
        if(card >= 2 && card <= 10)
            count += card; //Adds regular card numbers
        else if(card == KING || card == QUEEN || card == JACK){
            count += 10; //Adds face card numbers as 10
        } else if(card == ACE){
            count += 1; //Adds 1 for Aces
            nAces++;
        }
    }
    
    while(nAces > 0 && count < 12){
        nAces--; 
        count += 10; //Adds 10 more to Aces when count is less than 12
    }
    
    return count;
}

// Gets char representation of card
char getChar(int card){ 
    if(card >= 2 && card <= 9)
        return '0' + card;
    else if(card == 10)
        return 'T';
    else if(card == ACE)
        return 'A';
    else if(card == KING)
        return 'K';
    else if(card == QUEEN)
        return 'Q';
    else if(card == JACK)
        return 'J';
    else
        return '0'; //To find errors
}

// Prints hand
void PriHand(int hand[], int size){
    int i=0;
do {
    char handFun = getChar(hand[i]); //Sets getChar function to handFun char
    char *handPtr = &handFun;        //Pointer to handFun char
    cout << setw(2) << fixed << setprecision(1) << *handPtr << " ";
    i++;
} while (i<size);
    cout << endl;
}
