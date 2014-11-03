#include <stdio.h>

//void drawBoard(char** bs)
void drawBoard(char bs[3][3])
{
	printf( " %c | %c | %c \n", bs[0][0],bs[0][1],bs[0][2] );
	printf( "-----------\n");
	printf( " %c | %c | %c \n", bs[1][0],bs[1][1],bs[1][2] );
	printf( "-----------\n");
	printf( " %c | %c | %c \n", bs[2][0],bs[2][1],bs[2][2] );
}

int main()
{
	char boardState[3][3];
	char whoseTurn = 'x';

	// initialize the board state
	for(int i = 0; i < 3; i++ )
	{
		for(int j = 0; j < 3; j++ )
		{
			boardState[i][j] = ' ';
		}
	}

	// make some test moves
	boardState[1][1] = 'x';	
	boardState[1][2] = 'o';

	// Dave was WRONG!!!!
	//drawBoard((char**) boardState);
	drawBoard(boardState);
	
	return 0;
}
