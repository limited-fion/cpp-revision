#include <iostream>
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);

int main()
{
    runGame();

	return 0;
}//end main

void runGame()
{
    string winner = " "; // X, O, C
    string gameBoard[ROWS][COLS];

    initializeGameBoard(gameBoard);
    printCurrentBoard(gameBoard);

    bool xTurn = 1;

    while (winner == " ")
    {
        getUserInput(xTurn, gameBoard);
        printCurrentBoard(gameBoard);
        
        winner = getWinner(gameBoard);

        if (xTurn == 1)
        {
            xTurn = 0;
        }
        else
        {
            xTurn = 1;
        }
        
        if ((isBoardFull(gameBoard) == 1) && (winner == " "))
        {
            winner = "C";
        }
    }

    if (winner == "C")
    {
        cout << "Draw!" << endl;
    }
    else
    {
        cout << winner << " won!" << endl;
    }
}

void initializeGameBoard(string gameBoard[ROWS][COLS])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            gameBoard[row][col] = " ";
        }
    }
    cout << "Tic-tac-toe" << endl;
}

void printCurrentBoard(string gameBoard[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        cout << gameBoard[row][0] << " | " << gameBoard[row][1] << " | " << gameBoard[row][2] << endl;
    }
    cout << endl;
}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS])
{
    int inputRow = 0;
    int inputCol = 0;
    string player = "X";
    bool valid = 0;

    if (xTurn == 1)
    {
        player = "X";
    }
    else 
    {
        player = "O";
    }

    cout << "It is " << player << "'s turn" << endl;
    cout << "Please enter the row THEN the column, each from 0, 1 or 2, separated by a space" << endl;

    while (!valid)
    {
        cin >> inputRow;
        cin >> inputCol;

        if (((inputRow >= 0) && (inputRow <= 2)) && ((inputCol >= 0) && (inputCol <= 2)))
        {
            if (cellAlreadyOccupied(inputRow, inputCol, gameBoard))
            {
                cout << "Cell already occupied. Please try again!" << endl;
            }
            else
            {
                gameBoard[inputRow][inputCol] = player;
                valid = 1;
            }
        }
        else
        {
            cout << "Invalid row / column. Please try again!" << endl;
        }
    }
}

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
    if (gameBoard[row][col] == " ")
    {
        return false;
    }
    return true;
}

string getWinner(string gameBoard[ROWS][COLS])
{
    string winner = " ";

    for (int row = 0; row < 3; row++)
    {
        if ((gameBoard[row][0] == "X") && (gameBoard[row][1] == "X")  && (gameBoard[row][2] == "X"))
        {
            winner = "X";
        }
        else if ((gameBoard[row][0] == "O") && (gameBoard[row][1] == "O")  && (gameBoard[row][2] == "O"))
        {
            winner = "O";
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if ((gameBoard[0][col] == "X") && (gameBoard[1][col] == "X") && (gameBoard[2][col] == "X"))
        {
            winner = "X";
        }
        else if ((gameBoard[0][col] == "O") && (gameBoard[1][col] == "O") && (gameBoard[2][col] == "O"))
        {
            winner = "O";
        }
    }

    if ((gameBoard[0][0] == "X") && (gameBoard[1][1] == "X") && (gameBoard[2][2] == "X"))
    {
        winner = "X";
    }
    else if ((gameBoard[3][0] == "O") && (gameBoard[2][1] == "O") && (gameBoard[0][2] == "O"))
    {
        winner = "O";
    }

    return winner;
}

bool isBoardFull(string gameBoard[ROWS][COLS])
{
    bool full = 0;
    int spaces = 0;

    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            if (gameBoard[row][col] == " ")
            {
                spaces++;
            }
        }
    }

    if (spaces == 0){
        full = 1;
    }

    return full;
}