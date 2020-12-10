#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ROW8 8
#define COL8 8

void fillingViewArry(char viewArry[][COL8]);
void fillingArry(int boardEight[][COL8], int rows, int cols);
void addingBombs(int boardEight[][COL8], int numOfBombs);
void bombsCheck(int boardEight[][COL8], int rows, int cols);
void countingAround(int boardEight[][COL8], int i, int j, int rows, int cols);
void printArry(int boardEight[][COL8], int rows, int cols);
void printViewArry(char viewArry[][COL8]);

void main()
{
	int boardEight[ROW8][COL8];
	char viewArry[ROW8][COL8];
	int rows = 8;
	int cols = 8;
	int numOfBombs = 8;
	int chooseRow, chooseCol;
	char clientChoice ='*';

	fillingArry(boardEight, rows, cols);
	fillingViewArry(viewArry);
	addingBombs(boardEight, numOfBombs);
	bombsCheck(boardEight, rows, cols);
	//countingAround(boardEight, i, j, rows, cols);
	printArry(boardEight, rows, cols);
	printViewArry(viewArry, rows, cols);
	while (clientChoice != '*')//didnt open a bomb
	{
		printViewArry(viewArry, rows, cols);
		printf("Please enter a row and a cole: ");
		scanf("%d%d", &chooseRow, &chooseCol);
		char charViewOfInt = changingArrys(boardEight, chooseRow, chooseCol);
		viewClientChoiceArry(viewArry, charViewOfInt, chooseRow, chooseCol);
	}
	// adding the rest of the bombs.
	printViewArry(viewArry);

}
//arry
//filling it with spaces (0) and * (-9) randomly
//cheking the boothes arount it 
//
//printing it 

	void fillingViewArry(char viewArry[][COL8])
	{
		int i, j;
		for (i = 0; i < ROW8; i++)
		{
			for (j = 0; j < COL8; j++)
			{
				viewArry[i][j] = 'X';
			}
		}
	}

	void fillingArry(int boardEight[][COL8], int rows, int cols)
	{
		int i, j;

		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				boardEight[i][j] = 0;
			}
		}

	}

	void addingBombs(int boardEight[][COL8], int numOfBombs)
	{
		int b, row, col;
		for (b = 0; b < numOfBombs; b++)
		{
			row = rand() % numOfBombs;
			col = rand() % numOfBombs;

			if (boardEight[row][col] == -9)
				b++;
			else
				boardEight[row][col] = -9;
		}
	}

	//cheking for bobms
	void bombsCheck(int boardEight[][COL8], int rows, int cols)
	{
		int i, j;
		for (i = 0; i <= rows; i++)
		{
			for (j = 0; j < cols; j++)
			{
				if (boardEight[i][j] < 0)
					countingAround(boardEight, i, j, rows, cols);
				else
					continue;
			}
		}
	}

	void countingAround(int boardEight[][COL8], int i, int j, int rows, int cols)
	{
		if (i == 0 && j == 0) // |-  first lest corner
		{
			boardEight[i][j + 1] = boardEight[i][j + 1] + 1;
			boardEight[i + 1][j] = boardEight[i + 1][j] + 1;
			boardEight[i + 1][j + 1] = boardEight[i + 1][j + 1] + 1;
		}
		else if (i == 0 && j == rows - 1) // -| firt right corner
		{
			boardEight[i][j - 1] = boardEight[i][j - 1] + 1;
			boardEight[i + 1][j - 1] = boardEight[i + 1][j - 1] + 1;
			boardEight[i + 1][j] = boardEight[i + 1][j] + 1;
		}
		else if (i == rows - 1 && j == 0) // |_
		{
			boardEight[i][j + 1] = boardEight[i][j + 1] + 1;
			boardEight[i - 1][j] = boardEight[i - 1][j] + 1;
			boardEight[i - 1][j + 1] = boardEight[i - 1][j + 1] + 1;
		}
		else if (i == rows - 1 && j == cols - 1) // _|
		{
			boardEight[i][j - 1] = boardEight[i][j - 1] + 1;
			boardEight[i - 1][j - 1] = boardEight[i - 1][j - 1] + 1;
			boardEight[i - 1][j] = boardEight[i - 1][j] + 1;

		}
		else if (i == 0)
		{
			boardEight[i][j - 1] = boardEight[i][j - 1] + 1;
			boardEight[i][j + 1] = boardEight[i][j + 1] + 1;
			boardEight[i + 1][j - 1] = boardEight[i + 1][j - 1] + 1;
			boardEight[i + 1][j] = boardEight[i + 1][j] + 1;
			boardEight[i + 1][j + 1] = boardEight[i + 1][j + 1] + 1;
		}
		else if (j == 0)
		{
			boardEight[i - 1][j] = boardEight[i - 1][j] + 1;
			boardEight[i + 1][j] = boardEight[i + 1][j] + 1;
			boardEight[i - 1][j + 1] = boardEight[i - 1][j + 1] + 1;
			boardEight[i][j + 1] = boardEight[i][j + 1] + 1;
			boardEight[i + 1][j + 1] = boardEight[i + 1][j + 1] + 1;
		}
		else if (i == rows - 1)
		{
			boardEight[i][j - 1] = boardEight[i][j - 1] + 1;
			boardEight[i][j + 1] = boardEight[i][j + 1] + 1;
			boardEight[i - 1][j - 1] = boardEight[i - 1][j - 1] + 1;
			boardEight[i - 1][j] = boardEight[i - 1][j] + 1;
			boardEight[i - 1][j + 1] = boardEight[i - 1][j + 1] + 1;
		}
		else if (j == cols - 1)
		{
			boardEight[i - 1][j] = boardEight[i - 1][j] + 1;
			boardEight[i + 1][j] = boardEight[i + 1][j] + 1;
			boardEight[i - 1][j - 1] = boardEight[i - 1][j - 1] + 1;
			boardEight[i][j - 1] = boardEight[i][j - 1] + 1;
			boardEight[i + 1][j - 1] = boardEight[i + 1][j - 1] + 1;
		}

		else
		{	//first row
			boardEight[i - 1][j - 1] = boardEight[i - 1][j - 1] + 1;
			boardEight[i - 1][j] = boardEight[i - 1][j] + 1;
			boardEight[i - 1][j + 1] = boardEight[i - 1][j + 1] + 1;
			//middle row
			boardEight[i][j - 1] = boardEight[i][j - 1] + 1;
			boardEight[i][j + 1] = boardEight[i][j + 1] + 1;
			//last row
			boardEight[i + 1][j - 1] = boardEight[i + 1][j - 1] + 1;
			boardEight[i + 1][j] = boardEight[i + 1][j] + 1;
			boardEight[i + 1][j + 1] = boardEight[i + 1][j + 1] + 1;
		}
	}

	void printArry(int boardEight[][COL8], int rows, int cols)
	{

		int i, j, k, r, s;
		printf("    ");
		for (r = 0; r < rows; r++)
			printf("  %d  ", r);

		printf("\n");

		printf(" ");
		for (k = 0; k < rows + 3; k++)
			printf("____");
		printf("\n");

		for (i = 0; i < rows; i++)
		{
			printf("   %d ", i);
			for (j = 0; j < cols; j++)
			{

				printf("| %d |", boardEight[i][j]);

			}
			printf("\n");
		}

		printf(" ");
		for (s = 0; s < rows + 1; s++)
			printf("_____");
		printf("\n");

	}

void printViewArry(char viewArry[][COL8])
{
	int i, j, k, r, s;
	printf("    ");
	for (r = 0; r < ROW8; r++)
		printf("  %d  ", r);

	printf("\n");

	printf(" ");
	for (k = 0; k < ROW8 + 3; k++)
		printf("____");
	printf("\n");

	for (i = 0; i < ROW8; i++)
	{
		printf("   %d ", i);
		for (j = 0; j < COL8; j++)
		{
			printf("| %c |", viewArry[i][j]);
		}
		printf("\n");
	}

	printf(" ");
	for (s = 0; s < ROW8 + 1; s++)
		printf("_____");

	printf("\n");

}

//int chooseRowCol(char viewArry[][COL8])//print the arry and asking to enter a place in the board
//{
//	int num;
//
//		printViewArry(viewArry);
//		scanf("%d", &num);
//
//		return num; // how do i return two valuse?
//		//taking the place and changing the X to the number
//}


char changingArrys(int array[8][8], int a, int b) {}

/*
char changingArrys(int boardEight[][COL8], int row, int col)
{
	
	if (boardEight[row][col] == 0)
		return ' ';
	else if (boardEight[row][col] < 0)
		return '*';
	else
		return boardEight[row][col] +'0';
		
		}
		*/


void viewClientChoiceArry(char viewArry[][COL8], char clientChoice, int row, int col)
{
	viewArry[row][col] = clientChoice;
	//end game and show rest of the bombs

}


// getting the place in the board from the player
// changing it from int to char
//putting it in the right place in the char arry


//func that enter the bombs to the view arry//

