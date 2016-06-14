#include "game.h"


void getNextMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], char * token,Player * player);
void getInitialPosition(Cell board[BOARD_HEIGHT][BOARD_WIDTH],Player * player,char * token);
void getBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],char * token);

void playGame()
{
	Boolean loaded = FALSE;
	Boolean hasInit = FALSE;
	Player player;
	Cell board[BOARD_HEIGHT][BOARD_WIDTH];
	char load[BUFFER_SIZE];
	char *token;
	char *readin;


	playgame_menu();
	initialiseBoard(board);
	printf("Please enter to continue...\n");
	while(getchar() != '\n');
	displayBoard(board, NULL);
	twoCommands_menu();
	while(TRUE)
	{
		if(loaded && hasInit)
		{
			fourCommands_menu();
		}
		else if (loaded)
		{
			threeCommands_menu();
		}


		readin = fgets(load,80,stdin);
		load[strlen(readin) - 1] = '\0';
		token = strtok(readin,DELIMS);
		if(strcmp(token,COMMAND_LOAD) == 0)
		{
			token = strtok(NULL,DELIMS);
			getBoard(board,token);
			loaded = TRUE;
		}
		else if(strcmp(token,COMMAND_INIT) == 0)
		{
			if(!loaded)
			{
				printf("INVALID INPUT.\n");
			}
			else
			{
				getInitialPosition(board,&player,token);
				displayBoard(board,&player);
				hasInit = TRUE;
			}
		}
		else if (strcmp(token,COMMAND_QUIT) == 0)
		{
			int moves = (int) player.moves;  
			printf("Total player moves : %d\n",moves);
			break;
		}
		else {
			getNextMove(board,token,&player);
		}
	}
}


void getBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],char * token){
	if(strcmp(token,"1") == 0)
	{
		loadBoard(board, BOARD_1);
		displayBoard(board,NULL);
	}
	else if(strcmp(token,"2") == 0)
	{
		loadBoard(board, BOARD_2);
		displayBoard(board,NULL);
	}
	else
	{
		printf("ERROR : INVALID INPUT.\n\n");
		printf("Please enter a correct command.\n");
	}
}

void getInitialPosition(Cell board[BOARD_HEIGHT][BOARD_WIDTH],Player * player,char * token){

	Position position;
	Direction direction;
	token = strtok(NULL, DELIMS);

	/*- get 'y' -*/
	if(is_int(token)){
		position.y= atoi(token);
		token = strtok(NULL,DELIMS);

	}
	else
	{
		printf("INVALID INPUT\n");
	}

	/*- get 'x' -*/
	if(is_int(token)){
		position.x = atoi(token);
		token = strtok(NULL,DELIMS);
	}
	else
	{
		printf("INVALID INPUT\n");
	}

	/*- get 'direction' -*/
	if(strcmp(token,"west") == 0)
	{
		direction = WEST;
	}
	else if(strcmp(token,"south") == 0)
	{
		direction = SOUTH;
	}
	else if(strcmp(token,"east") == 0)
	{
		direction = EAST;
	}
	else if(strcmp(token,"north") == 0)
	{
		direction = NORTH;
	}
	else
	{
		printf("Please enter the direction correctl (north,east,south,west).\n");
	}


	/* initialise player position on the board */
	initialisePlayer(player,&position,direction);

	if(placePlayer(board,position) == TRUE)
	{
		position.x = player->position.x;
		position.y = player->position.y;
		player->direction = direction;
		direction = atoi(token);
	}
	else{
		printf("INVALID INPUT\n");
	}
}

void getNextMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], char * token,Player * player){

	if ((strcmp(token,COMMAND_FORWARD) == 0) || (strcmp(token,COMMAND_FORWARD_SHORTCUT) == 0))
	{
		movePlayerForward(board,player);
		displayBoard(board,player);
	}
	else if ((strcmp(token,COMMAND_TURN_LEFT) == 0) || (strcmp(token,COMMAND_TURN_LEFT_SHORTCUT) == 0))
	{
		turnDirection(player,TURN_LEFT);
		displayBoard(board,player);
	}
	else if ((strcmp(token,COMMAND_TURN_RIGHT) == 0) || (strcmp(token,COMMAND_TURN_RIGHT_SHORTCUT) == 0))
	{
		turnDirection(player,TURN_RIGHT);
		displayBoard(board,player);
	}
	else{
		printf("Please try agian :)\n");
	}
}
