#include <iostream>
using namespace std;

void showBoard(char board [3][3]);
bool checkWinner(char board[3][3], char player);

int main(){
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout << "Player X goes first..." << endl;
    cout << endl;

    while(!gameOver)
    {
        showBoard(board);

        int row, col;
        cout << endl;

        cout << "Player" << currentPlayer << " enter your move (Row, Column)" << endl;
        cin >> row >> col;
        cout << endl;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;

            if (checkWinner(board, currentPlayer))
            {
                showBoard;
                cout << "Player" << currentPlayer << "wins" << endl;
                gameOver = true;
            }

            else
            {
                bool draw = true;
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (board[i][j] == ' ')
                        {
                            draw = false;
                            break;
                        }
                    }
                }
                if (draw)
                {
                    showBoard(board);
                    cout << "Its a tie!" << endl;
                    gameOver = true;
                }
            }
            if (currentPlayer == 'X') currentPlayer = 'O';
            else currentPlayer = 'X';
        }
        else
        cout << "Invalid move. Please try again" << endl;
    }
   
}

void showBoard(char board[3][3])
{
    cout << " 0 1 2 " << endl;
    for (int i = 0;  i< 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWinner(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        return true;

        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
        return true;
    }

    if (board[0][2] == player && board [1][1] == player && board [2][0] == player)
    return false;

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return false;
}