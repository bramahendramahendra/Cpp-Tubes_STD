#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>

using namespace std;
void gotoxy(int x, int y)
{
HANDLE hConsoleOutput;
COORD dwCursorPosition;
dwCursorPosition.X = x;
dwCursorPosition.Y = y;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
int main()
{

    gotoxy(30,10);
    cout << "Hello world!" << endl;
    return 0;
}
