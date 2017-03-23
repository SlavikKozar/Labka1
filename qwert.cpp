#include <iostream>
#include <conio.h>
#include <time.h>
#include <random>
using namespace std;
char name1[30];
char name2[30];
char table [3][3];
bool step;

void instruction()
{
    cout << "\t\t*** Krestiki noliki ***\n\n";
    cout << "Root :\n";
    cout << "Two players play on board 3*3\n";
    cout << "Win that person which make win combinations\n";
    cout << "Board is:\n";
    int l = 0;

    for(int i(0); i < 3; i++)
    {
        for(int j(0); j < 3; j++)
        {
            cout << "| " << l+1 << " ";
            table[i][j] = char(49+l);
            l++;
        }
        cout << " |";
        cout << endl;
    }

    cout << "\nPlease enter number that you would like!\n\n";
    cout << "Enter klavisha:\n\n";
	_getch();


}

bool input()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "| " << table[i][j] << " ";

        }
        cout << " |";
        cout << endl;
    }

    cout << endl;

    if(step)
        cout << "Xodut " << name1 << ": ";
        else
        cout << "Xodut " << name2 << ": " ;
    int n;
    cin >> n;
    if(n < 1 || n > 9)
    return false;

    int i, j;
    if(n % 3 == 0)
    {
        i = n/3-1;
        j = 2;
    }
    else
    {
        j = n%3-1;
        i = n/3;
    }

    if(table[i][j] == '0' || table[i][j] == 'X')
        return false;

    if(step)
    {
        table[i][j] = 'X';
        step = false;
    }
    else
    {
        table[i][j] = '0';
        step = true;
    }
    return true;
}

bool win()
{
    for(int i = 0; i < 3; i++)
        if((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))
        return true;
    else
        if((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))
        return true;
    else
        if(((table[0][0] == table[1][1]) && table[0][0] == table[2][2]) ||(table[0][2] == table[1][1] && table[0][2] == table[2][0]))
        return true;

    return false;
}
int  main()
{
    instruction();
	system("cls");

    cout << "Please enter 1 player:";
    cin.getline(name1,30);

    cout << "Please enter 2 player:";
    cin.getline(name2,30);

    srand(time(NULL));
    if(rand() & 1)
        step = true;
    else
        step = false;

    while(!win())
    {
        if(!input())
        {
            cout << "Error!\n";
			_getch();
        }
		system("cls");
    }

    if(step)
        cout << "Win --->" << name2 << endl;
    else
        cout << "Win ---->" << name1 << endl;
}
