//****************************************************************************
// Program Functionality and Purpose
//This is a program of the Rock Paper Scissor Game.
//Project started on 17/02/2025
//****************************************************************************

// header file
#include <iostream>
#include <string>


using namespace std;

enum class objectType {
    ROCK, PAPER, SCISSORS
};

//Functions
void displayRules();
bool validateSelection(char selection);
objectType initializeObject (char selection);
string convertEnum(objectType object);
void gameResult(objectType play1, objectType play2, int win1, int win2 );
void gameResult(objectType play1, objectType play2, string& player1Name, string& player2Name);


//Program Execution Starts Here
int main() {
// Declare variables
    string player1Name;
    string player2Name;
    char ans;
    objectType play1, play2;

    char selection1;
    char selection2;


    //Display a brief info and rules about the game.
    displayRules();

    //Prompt the user to know if the user would like to play the game.
    cout << "Would you like to play RPS, Yes(y/Y) or No(n,N) : ";
    cin >> ans;
    cout << endl;
    cin.ignore();

    //statements runs when ans = y
    if (ans == 'Y' || ans == 'y') {
//        requesting and collecting player1 details
        cout << "Player 1 Please enter your name: ";
        getline(cin,player1Name);
        cout << endl;

//        requesting and collecting player2 details
        cout << "Player 2 Please enter your name: ";
        getline(cin,player2Name);
        cout << endl;

//        Requesting players to make choice.
//        Player 1
        cout << player1Name << ", please make you choice, R:rock , P:paper, S:scissors" << endl;
        cout << "Choice: ";
        cin >> selection1;

//        Player 2
        cout << player2Name << ", please make you choice, R:rock , P:paper, S:scissors" << endl;
        cout << "Choice: ";
        cin >> selection2;

//        Call a function to validate the players answer if answers pass validation, proceed to process result
        if (validateSelection(selection1) && validateSelection(selection2) ) {

            //initialize each players choice with the respect object.
            play1 = initializeObject(selection1);
            play2 = initializeObject(selection2); // each players choice initialize

            // if the game is a tie
            if ( play1 == play2 ) {
                cout << "Both players chose " << convertEnum(play1) << " the game is a tie! " << endl;
            }

            if ( play1 != play2 ) {
//        Call the gameResult function to process the result.
                gameResult(play1, play2, player2Name, player2Name);

            }

        }
        else
        {
            cout << "Players input invalid" << endl;
        }



    }

    //statements runs when ans = n
    if (ans == 'n' || ans == 'N') {
        cout << "Adious" << endl;
    }




    return 0;
}

void displayRules() {
    cout << "Rock Paper Scissors also known as RPS, is a simple hand gesture game" << endl;
    cout << "It is typically played between two people" << endl;
    cout << endl;
    cout << "Rules: " <<endl;
    cout << "1. Rock beats Scissors ( by crushing it)" << endl;
    cout << "2. Scissors beats paper ( by cutting it" << endl;
    cout << "3. Paper beats rock (b covering it)" << endl;
    cout << endl;
} // displays the welcome message as well as the rulse of the game.

bool validateSelection(char selection) {
    switch (selection) {
        case 'S':
        case 's':
        case 'P':
        case 'p':
        case 'R':
        case 'r':
            return true;

        default: return false;
    }
}  //validates the player's answer

objectType initializeObject (char selection) {
    objectType object;

    switch (selection) {
        case 'S':
            object = objectType::SCISSORS;
        case 's':
            object = objectType::SCISSORS;
            break;

        case 'P':
            object = objectType::PAPER;
        case 'p':
            object = objectType::PAPER;
            break;

        case 'R':
            object = objectType::ROCK;
        case 'r':
            object = objectType::ROCK;
            break;

        default: cout << "object not found" << endl;
    }

    return object;
} //set objects passed on the user's choice.

string convertEnum(objectType object) {
    switch (object) {
        case objectType::ROCK:
            return "Rock";

        case objectType::PAPER:
            return "Paper";

        case objectType::SCISSORS:
            return "Scissors";

        default: cout << "Error line 165";
    }

}  //convert the enumObject to string for output.

void gameResult(objectType play1, objectType play2, string& player1Name, string& player2Name) {

    if(((play1 == objectType:: ROCK )&& (play2 == objectType:: SCISSORS))||((play1 == objectType:: PAPER) && (play2 == objectType::ROCK))||((play1 == objectType:: SCISSORS) && (play2 == objectType::PAPER))) {
        cout << player1Name << "wins" << endl;
    }
    else
        cout << player2Name << " wins" << endl;
}

