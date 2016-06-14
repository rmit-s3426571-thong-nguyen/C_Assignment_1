#include "board.h"

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
	{ BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
	{ EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
	{ BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
	{ EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	/**
	 * Initialise the board - set all the cells in the board to EMPTY.
	 */
	int row,col;
	for (row = 0; row < BOARD_HEIGHT; row++)
	{
		for (col = 0; col < BOARD_WIDTH; col++)
		{
			board[col][row] = EMPTY;

		}
	}
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
	Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
	/**
	 * Load the board - set all the cells in board to 
	 * those present in boardToLoad.
	 */
	int row,col;
	for (row = 0; row < BOARD_HEIGHT; row++)
	{
		for (col = 0; col < BOARD_WIDTH; col++)
		{
			board[col][row] = boardToLoad[col][row];
		}
	}

}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
	/**
 	 * Try to place the PLAYER cell at the provided position.
     */
	if (position.x >=  BOARD_WIDTH || position.x <= BOARD_WIDTH_MIN)
	{
		return FALSE;
	}
	else if (position.y >=  BOARD_HEIGHT || position.y <= BOARD_HEIGHT_MIN)
	{
		return FALSE;
	}
	else if (board[position.x][position.y] != EMPTY)
	{
		return FALSE;
	}
	else
	{   
		board[position.x][position.y] = PLAYER;
		return TRUE;
	}
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
	Player * player)
{
	Position newPosition = getNextForwardPosition(player);

	if (newPosition.x >= BOARD_WIDTH || newPosition.x < BOARD_WIDTH_MIN)
	{
		printf("ERROR: The car is at the edge of the board and cannot move further in that direction.\n\n");
		return OUTSIDE_BOUNDS;
	}
	else if (newPosition.y >= BOARD_HEIGHT || newPosition.y < BOARD_HEIGHT_MIN)
	{
		printf("ERROR: The car is at the edge of the board and cannot move further in that direction.\n\n");
		return OUTSIDE_BOUNDS;
	}

	else if (board[newPosition.y][newPosition.x] != EMPTY)
	{
		printf("Error: The car cannot move forward because the road is blocked. \n\n");
		return CELL_BLOCKED;
	}
	else if (board[newPosition.y][newPosition.x] == EMPTY)
	{
		board[player->position.y][player->position.x] = EMPTY;
		player->position.x = newPosition.x;
		player->position.y = newPosition.y;
		updatePosition(player,newPosition);
		board[newPosition.y][newPosition.x] = PLAYER;
		return PLAYER_MOVED;
	}
	return PLAYER_MOVED;
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
	int row, col;
	printf("| |0|1|2|3|4|5|6|7|8|9|\n");
	for (col = 0; col < BOARD_HEIGHT; col++)
	{
		printf("|%d|",col);
		for (row = 0; row < BOARD_WIDTH; row++)
		{
			if (board[col][row] == EMPTY)
			{
				printf(EMPTY_OUTPUT);
			}
			else if (board[col][row] == BLOCKED)
			{
				printf(BLOCKED_OUTPUT);
			}
			else if(board[col][row] == PLAYER)
			{

				displayDirection(player->direction);
			}
			printf("|");
		}
		printf("\n");
	}
}
