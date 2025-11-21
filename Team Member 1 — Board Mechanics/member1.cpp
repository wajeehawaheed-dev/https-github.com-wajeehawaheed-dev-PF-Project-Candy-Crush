#include <iostream>
#include <iomanip>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time(NULL)
#include <conio.h>

using namespace std;

void SwappingCandies()
{

}

int GetKey()		//for getting shift, another special character
{
	return _getch();   //returns ASCII or special key codes
}

int GetDirectionFromArrowKeys()		
{
	char arrowKey = _getch();

	//Windows uses -32 or 224 to identify it
	while (arrowKey != 224 && arrowKey != -32)		//tells computer next key will be special character
	{
		cout << "only arrow keys are allowed: ";
		arrowKey = _getch();
	}


	char key = _getch();
	while (key != 72 && key != 80 && key != 75 && key != 77)		//keep on asking user to enter arrow keys
	{
		cout << "only arrow keys are allowed : ";
		while (arrowKey != 224 && arrowKey != -32)
		{
			arrowKey = _getch();
		}
		key = _getch();	//actual key (one of the arrow keys)

	}

	if (key == 72)			//ASCII of up key
		return 1;
	else if (key == 80)		//ASCII of down key
		return 2;
	else if (key == 75)		//ASCII of left key
		return 3;
	else if (key == 77)		//ASCII of right key
		return 4;

	else
		return 0;		//key other than up, down, left, right
}

void DisplayGrid(int grid[][20], int gridSize, int candyTypes, int level)
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			do
			{
				grid[i][j] = rand() % candyTypes + 1;		//Random generator for position & input of candies

			} while ((j >= 2 && grid[i][j] == grid[i][j - 1] && grid[i][j] == grid[i][j - 2]) ||
					(i >= 2 && grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j]));
			//for stopping initial matches of candies, before any move from user
					
		}
	}

	cout << "The grid of level " << level << " is : " << endl;
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{	
	int grid[20][20];
	int level;

	
	do
	{
		cout << "Which level do you want to play: ";
		cin >> level;
	} while (level < 1 || level > 10);
	//5 types of candies (red,blue,green,yellow,purple)

	if (level == 1)					//	Level 1: Very Easy
	{
		int gridSize = 8;			//8x8 grid
		int candyTypes = 5;		
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if(level == 2)				//	Level 2: Very Easy
	{
		int gridSize = 8;			//8x8 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 3)			//	Level 3: Easy
	{
		int gridSize = 9;			//9x9 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 4)			//	Level 4: Easy
	{
		int gridSize = 9;			//9x9 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 5)			//	Level 5: Medium
	{
		int gridSize = 10;			//10x10 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}

	else if (level == 6)			//	Level 6: Medium
	{
		int gridSize = 10;			//10x10 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 7)			//	Level 7: Hard
	{
		int gridSize = 11;			//11x11 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 8)			//	Level 8: Hard
	{
		int gridSize =11;			//11x11 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 9)			//	Level 9: Very Hard
	{
		int gridSize = 12;			//12x12 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	else if (level == 10)			//	Level 10: Very Hard
	{
		int gridSize = 12;			//12x12 grid
		int candyTypes = 5;
		DisplayGrid(grid, gridSize, candyTypes, level);
	}
	
	
	int direction = GetDirectionFromArrowKeys();

	if (direction == 1)
		cout << "up";
	if (direction == 2)
		cout << "down";
	if (direction == 3)
		cout << "left";
	if (direction == 4)
		cout << "right";

	int defaultR = 0;
	int defaultC = 0;



}