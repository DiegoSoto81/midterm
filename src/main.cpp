#include <iostream>
using namespace std;

void showBoard(char board [3][3]);
bool checkWinner(char board[3][3], char player);

int main(){
    char board[3][3] = {}
   
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

        
    }
}