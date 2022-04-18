#include <iostream>
# include <cstdlib>
#include <ctime>
using namespace std;

void Go (char arr [][5], int x, int y, int who, bool end) {
    if (who == 1) {
        switch (x) {
            case 1:
                arr [0][0] = 'X';
            break;
            case 2:
                arr [0][2] = 'X';
                break;
            case 3:
                arr [0][4] = 'X';
            break;
            case 4:
                arr [2][0] = 'X';
            break;
            case 5:
                arr [2][2] = 'X';
            break;
            case 6:
                arr [2][4] = 'X';
            break;
            case 7:
                arr [5][0] = 'X';
            break;
            case 8:
                arr [5][2] = 'X';
            break;
            case 9:
                arr [5][4] = 'X';
            break;
    }
        for (int i =0; i< 5; i++)
        {
            for (int j =0; j < 5; j++)
            {
                cout << arr [i][j] << " ";
                if ((arr [0][j] == 'X' && arr [2][j+1] == 'X' && arr [4][j+2] == 'X') || (arr [0][j] == 'X' && arr [2][j] == 'X' && arr [4][j] == 'X') || (arr [0][j] == 'X' && arr [2][j-1] == 'X' && arr [4][j-2] == 'X')){
                    end = true;
                    cout << "Game ended";
                    return;
                }
            }
            cout << endl;
        }
        who = 2;
        cout << "Choose your number: ";
        cin >> y;
    }
        else {
        switch (y) {
            case 1:
                arr [0][0] = 'O';
            break;
            case 2:
                arr [0][2] = 'O';
                break;
            case 3:
                arr [0][4] = 'O';
            break;
            case 4:
                arr [2][0] = 'O';
            break;
            case 5:
                arr [2][2] = 'O';
            break;
            case 6:
                arr [2][4] = 'O';
            break;
            case 7:
                arr [5][0] = 'O';
            break;
            case 8:
                arr [5][2] = 'O';
            break;
            case 9:
                arr [5][4] = 'O';
            break;
            }
            for (int i =0; i< 5; i++)
            {
                for (int j =0; j < 5; j++)
                {
                    cout << arr [i][j] << " ";
                    if ((arr [0][j] == 'O' && arr [2][j+1] == 'O' && arr [4][j+2] == 'O') || (arr [0][j] == 'O' && arr [2][j] == 'O' && arr [4][j] == 'O') || (arr [0][j] == 'O' && arr [2][j-1] == 'O' && arr [4][j-2] == 'O')){
                        end = true;
                        cout << "Game ended";
                        return;
                    }
                }
                cout << endl;
            }
            who = 1;
            x = (rand () % 9 );
        }
    if (end == true)
        return;
    Go (arr, x, y, who, end);
}
int main()
{
    bool end = false;
    int who =0;
    srand (time (0));
    int x;
    int y = 0;
    char desk [5][5] = {
        { '1', '|', '2', '|', '3'},
        {'-', '-', '-', '-', '-'},
        { '4', '|', '5', '|', '6'},
        {'-', '-', '-', '-', '-'},
        { '7', '|', '8', '|', '9'}
    };
    for (int i =0; i< 5; i++)
    {
        for (int j =0; j < 5; j++)
        {
            cout << desk [i][j] << " ";
        }
        cout << endl;
    }
    
    if ((rand() % 2) == 1 )
    {
        cout << "The player goes first!" << endl;
        who = 2;
        cout << "Choose your number: ";
        cin >> y;
    }
    else
    {
        cout << "Computer goes first!" << endl;
        who = 1;
        x = (rand ()%9);
    }
        Go (desk, x, y, who, end);
    return 0;
}
