//****************************************************************************
// Program Functionality and Purpose
// ROCK PAPER SCISSOR GAME.
// Recheck the computer selection system.
//****************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class objectType {
    ROCK, PAPER, SCISSORS
};

//Functions
void Welcome();

char getSelection();

bool validateUserInput(char userInput);

objectType objectSelect(char selection);

string convertEnum(objectType play);

void gameResult(objectType play1, objectType play2, string play1Name, string play2Name, int &gamecount, int &win1count,
                int &win2count);

void displayChoice(string& play1Name, string& play2Name,objectType play1,objectType play2);

//program starts
int main() {
// Declare variables
    static int gamecount, win1count, win2count;
    static char selection1;
    static char selection2;
    char response;
    static string play1Name, play2Name;
    objectType play1, play2;

    srand(time(0));

    int randomNumber = (rand() % 3) + 1;


//display welcome message
    Welcome();
//choose the game mode
    cout << "Choose a Game Mode: \n";
    cout << "1. Single Player (You vs Computer) \n";
    cout << "2. Multiplayer (Player 1 vs Player 2)\n";
    cout << "Enter your choice (1 or 2): ";
    cin.get(response);
    cout << endl;

    //for single mode
    if (response == '1') {
        //Acquiring user data
        cout << "What is your name player: ";
        cin >> play1Name;
        cin.clear();
        cin.ignore();
        cout << endl;

        //computer
        play2Name = "Computer";
        
        //get selection
        selection1 = getSelection();

        //validate selection
        validateUserInput(selection1);

        //Computer make random choice.

        switch (randomNumber) {
            case 1:
                selection2 = 'R';
                break;
            case 2:
                selection1 = 'S';
                break;
            case 3:
                selection2 = 'P';
                break;

            default:
                cout << "error at line 74" << endl;
        }

        //Processing the Game Result
        play1 = objectSelect(selection1);
        play2 = objectSelect(selection2);
        cout << endl;

        //Make Decision
        gameResult(play1, play2, play1Name, play2Name, gamecount, win1count, win2count);

        // Scoreboard




    }

    //for multiplayer mode
    if (response == 2) {

    }

    //invalide output.


    return 0;
}

void Welcome() {
    cout << "Welcome to the Ultimate Rock, Paper, Scissors Game! " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << " Rules of the Game:" << endl;
    cout << "1. Rock  beats Scissors " << endl;
    cout << "2. Paper beats Rock " << endl;
    cout << "3. Scissors  beats Paper " << endl;
    cout << "4. If both players choose the same, it's a tie! " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << " Get ready to play and see who wins! " << endl;
    cout << endl;
}

char getSelection() {
    //get selection
    char userInput;
    cout << "Choose your move: \n";
    cout << "R - Rock \n";
    cout << "P - Paper \n";
    cout << "S - Scissors ✂\n";
    cout << "Enter your choice (R, P, S): ";
    cin >> userInput;
    cin.ignore();

    return userInput;
}

bool validateUserInput(char userInput) {
    switch (userInput) {
        case 'S':
        case 's':
        case 'R':
        case 'r':
        case 'P':
        case 'p':
            return true;

        default:
            return false;
    }
}

objectType objectSelect(char selection) {
    objectType object;
    switch (selection) {
        case 'R':
        case 'r':
            object = objectType::ROCK;
            break;
        case 'S':
        case 's':
            object = objectType::SCISSORS;
            break;
        case 'P':
        case 'p':
            object = objectType::PAPER;
            break;
    }
    return object;
}

string convertEnum(objectType play) {
    string converted;

    if (play == objectType::PAPER) {
        converted = "Paper";
    }
    if (play == objectType::SCISSORS) {
        converted = "scissors";
    }
    if (play == objectType::ROCK) {
        converted = "rock";
    }
    return converted;
}

void gameResult(objectType play1, objectType play2, string play1Name, string play2Name, int &gamecount, int &win1count,
                int &win2count) {
    if (play1 == play2) {
        cout << "The game is a tie, both players choose: " << convertEnum(play1) << endl;
        gamecount++;
    }

    if (play1 == objectType::PAPER && play2 == objectType::SCISSORS ||
        play1 == objectType::PAPER && play2 == objectType::ROCK ||
        play1 == objectType::SCISSORS && play2 == objectType::PAPER) {
        cout << play1Name << " wins the game!" << endl;
        win1count++;

        displayChoice(play1Name, play2Name, play1, play2);

    } else
        cout << play2Name << " wins the game!" << endl;
    win2count++;
}

void scoreBoard(int &gamecount, string &play1Name, string &play2Name, int &win1count, int &win2count) {
    cout << " -----------------------Score Board------------------------" << endl;
    cout << "The number of games played : " << gamecount;
    cout << play1Name << win1count << endl;
    cout << play2Name << win1count << endl;
    cout << "Thank you for playing the game" << endl;
}

void displayChoice(string& play1Name, string& play2Name,objectType play1,objectType play2) {
    cout << play1Name << " choses: " << convertEnum(play1) << " and " << play2Name << " choses: " << convertEnum(play2);
}