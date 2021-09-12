#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
using namespace std;

int main()
{
e:
    string name;
    cout << "Enter the username     ----->     ";
    cin >> name;
    cout << endl;
    string inst;
a:
    cout << "Do you wish to read the instructions ? (yes/no) ";
    cin >> inst;
    cout << endl;
    if (inst == "yes")
    {
        cout << "-----------------  instructions  -----------------" << endl
             << endl
             << "The word game is such that a grid of random letters is provided" << endl
             << "This grid contains names of some colours" << endl
             << "In order to gain points you need to find those colour names in the grid" << endl
             << "Type the word and press enter" << endl
             << "You have the option to play in two levels.You can select one amoung the two" << endl
             << "For every correct guess a point is added" << endl
             << "In case you comeup with a wrong answer and cannot find any word you have the option to get hints" << endl
             << "You get 2 hints and you can select which hint you prefer among the 2" << endl;

        cout << endl
             << "************************  START  ***************************" << endl;
    }
    else if (inst == "no")
    {
        cout << "************************  START  ***************************" << endl;
        cout << endl;
    }
    else
    {
        cout << "Invalid output" << endl
             << "Select yes or no" << endl;
        goto a;
    }
    cout << endl;
b:
    cout << "Enter the level you wish to play in : " << endl
         << "1.Easy" << endl
         << "2.difficult" << endl;
    cout << endl;
    int lines, n, row, col;
    int level;
    cin >> level;

    cout << endl;
    if (level == 1)
    {
        lines = 10;
    }
    else if (level == 2)
    {
        lines = 15;
    }
    else
    {
        cout << "Invalid input" << endl
             << "Only two levels are available...... select 1/2" << endl;
        goto b;
    }

    system("cls");
    cout << "         LETS GO!!       " << endl
         << endl;
    string arr[10] = {"black", "indigo", "blue", "green", "yellow", "orange", "red", "purple", "pink", "brown"};

    char matrix[lines][lines];
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            int r = rand() % 26;
            matrix[i][j] = 'a' + r;
            for (int n = 0; n < 10; n++)
            {
                if (arr[n].length() % 2 == 0)
                {
                    row = rand() % lines;
                    if (level == 1)
                    {
                        col = rand() % 4;
                    }
                    else
                    {
                        col = rand() % 9;
                    }
                    for (int k = 0; k < arr[n].length(); k++, col++)
                    {
                        matrix[row][col] = arr[n][k];
                    }
                }
                else
                {
                    col = rand() % lines;
                    if (level == 1)
                    {
                        row = rand() % 4;
                    }
                    else
                    {
                        row = rand() % 9;
                    }
                    for (int k = 0; k < arr[n].length(); k++, row++)
                    {
                        matrix[row][col] = arr[n][k];
                    }
                }
            }
        }
    }
    for (int l = 0; l < lines; l++)
    {
        cout << endl;
        for (int p = 0; p < lines; p++)
        {
            cout << matrix[l][p] << " ";
        }
    }
    cout << endl
         << endl
         << "Try to guess the words....." << endl;
    int m;
    int score = 0;

    if (level == 1)
    {
        m = 6;
    }
    else
    {
        m = 9;
    }
    string ans[m];
    for (int i = 0; i < m; i++)
    {
        cin >> ans[i];

        bool flag = false;

        for (int j = 0; j < 10; j++)
        {
            if (ans[i] == arr[j])
            {
                flag = true;
            }
        }
        for (int s = 0; s < i; s++)
        {
            if (ans[s] == ans[i])
            {
                cout << "You have already guessed the word" << endl
                     << "Try another guess" << endl;
            }
        }
        if (flag == false)
        {
        c:
            cout << "Incorrect guess" << endl
                 << "Do you wish to take hint ?(yes/no)" << endl;
            int hn;
            string h;
            cin >> h;
            if (h == "yes")
            {
            d:
                cout << "You get 2 hints" << endl
                     << "Select the hint number you wish to get (1/2)" << endl;
                cin >> hn;
                if (hn == 1)
                {
                    cout << "Here is the list which contains the number of letters present in all the words to be found" << endl;
                    if (level == 1)
                    {
                        cout << arr[0].length() << endl
                             << arr[1].length() << endl
                             << arr[4].length() << endl
                             << arr[5].length() << endl
                             << arr[6].length() << endl
                             << arr[8].length() << endl;
                    }
                    else
                    {
                        for (int q = 0; q < 10; q++)
                        {
                            if (q == 3)
                            {
                                continue;
                            }
                            cout << arr[q].length() << endl;
                        }
                    }
                    cout << "Here you go .....Now try to guess" << endl;
                }
                else if (hn == 2)
                {
                    cout << "If the number of letters in the word is even then it is placed horizontally" << endl
                         << "The words with odd number of letters are placed vertically" << endl
                         << "Here you go .....Now try to guess" << endl;
                }
                else
                {
                    cout << "Invalid input" << endl
                         << "Only two hints are availabel.....Select 1/2" << endl;
                    goto d;
                }
            }
            else if (h == "no")
            {
                cout << "Try another guess" << endl;
            }
            else
            {
                cout << "Invalid input" << endl
                     << "Select yes or no" << endl;
                goto c;
            }
        }
        else
        {
            score++;
        }

        if (i == m - 1)
        {
            cout << endl
                 << endl
                 << "You have used your all trials" << endl
                 << endl
                 << "*********  GAME OVER  *********" << endl;
        }
    }

    cout << endl
         << endl
         << name << " "
         << "your total score is " << score << endl
         << endl;
f:
    cout << "Do you wish to play again? (yes/no)  ";
    string end;
    cin >> end;
    if (end == "yes")
    {
        goto e;
    }
    else if (end == "no")
    {
        cout << "___________________________________________________________________" << endl;
    }
    else
    {
        cout << "Enter valid input" << endl
             << "Select yes or no" << endl;
        goto f;
    }
    return 0;
}