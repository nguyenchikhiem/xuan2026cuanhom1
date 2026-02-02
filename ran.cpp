#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

int x = 10, y = 5;
int foodX = 5, foodY = 3;
int score = 0;
bool gameOver = false;
char dir = 'd';

void Draw() {
    system("cls");
    for (int i = 0; i < 22; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == y && j == x) cout << "O";
            else if (i == foodY && j == foodX) cout << "F";
            else cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 22; i++) cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        char c = _getch();
        if (c == 'w') dir = 'w';
        if (c == 's') dir = 's';
        if (c == 'a') dir = 'a';
        if (c == 'd') dir = 'd';
    }
}

void Logic() {
    if (dir == 'w') y--;
    if (dir == 's') y++;
    if (dir == 'a') x--;
    if (dir == 'd') x++;

    if (x == foodX && y == foodY) {
        score += 10;
        foodX = rand() % 18 + 1;
        foodY = rand() % 8 + 1;
    }

    if (x < 0 || x >= 20 || y < 0 || y >= 10)
        gameOver = true;
}

int main() {
    srand(time(0));
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(150);
    }

    cout << "GAME OVER!";
    return 0;
}

