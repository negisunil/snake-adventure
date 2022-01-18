
// Snake adventure in c++

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace:: std;

int i, j, breadth = 20, height = 20;
int gameover, score;
int x, y, dollarx,  dollary, flag;
void ClearScreen();

void draw()
{

    ClearScreen();
	system("color 1F");
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	for (i = 0; i < breadth; i++) {
		
		cout<<"\t\t\t\t\t\t\t\t\t\t";
		for (j = 0; j < height; j++) {
			if (i == 0 || i == height - 1
				|| j == 0
				|| j == breadth - 1) {
				cout<<"@";
			}
			else {
				if (i == x && j == y)
					 cout<<"~";
				else if (i == dollarx
						&& j ==  dollary)
					cout<<"$";
				else
					cout<<" ";
			}
		}
		cout<<"\n";
	}

	// Print the score after the
	// game ends
	cout<<"\n\t\t\t\t\t\tscore = "<<score<<endl;
	cout<<"\tPress X to quit the game";
}

// Function to generate the dollar
// within the boundary
void setup()
{
	gameover = 0;
	x = breadth / 2;
	y = height / 2;
	srand(time(0));
label1:
	dollarx = rand() % 19;
	if (dollarx == 0)
		goto label1;
label2:
	 dollary = rand() % 19;
	if ( dollary == 0)
		goto label2;
	score = 0;
}

// Function to take the input
void input()
{
	if (kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

void ClearScreen()
{	
COORD cursorPosition;	
cursorPosition.X = 0;	
cursorPosition.Y = 0;	
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

// Function for the logic behind
// each movement
void logic()
{
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	// If the game is over
	if (x <= 0 || x >= breadth-1
		|| y <= 0 || y >= height-1)
		gameover = 1;

	// If snake reaches the fruit
	// then update the score
	if (x == dollarx && y ==  dollary) {
		srand(time(0));
	label3:
		dollarx = rand() % 19;
		if (dollarx == 0)
			goto label3;

	// After eating the above fruit
	// generate new fruit
	label4:
		 dollary = rand() % 19;
		if ( dollary == 0)
			goto label4;
		score += 10;
	}
}


int main()
{
	int m, n;
	cout<<"\n\n#################################################### SNAKE ADVENTURE #################################################";

	
	setup();
	while (!gameover) {

		draw();
		input();
		logic();
	}
	return 0;
}

