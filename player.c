#include "player.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
    /** set the position, direction to the provided values
    * and set moves to 0.
    */
    player->position.x = position->x;
    player->position.y = position->y;
    player->direction = direction;
    player->moves = 0;
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /**
     * Turn the player's direction according to the direction 
     * of the player and the turn direction.
     */

    if (turnDirection == TURN_RIGHT)
    {
        switch(player->direction) {
            case NORTH:
            player->direction = EAST;
            break;
            case EAST:
            player->direction = SOUTH;
            break;
            case SOUTH:
            player->direction = WEST;
            break;
            case WEST:
            player->direction = NORTH;
        }

    }

    if (turnDirection == TURN_LEFT)
    {
        switch(player->direction){
            case NORTH:
            player->direction = WEST;
            break;
            case WEST:
            player->direction = SOUTH;
            break;
            case SOUTH:
            player->direction = EAST;
            break;
            case EAST:
            player->direction = NORTH;
            break;
        }
    }

}

Position getNextForwardPosition(const Player * player)
{
    /**
     * Gets the new position as if the player moved forward from the player's
     * current position and direction.
     */

    Position position;
    position.x = player->position.x,
    position.y = player->position.y;

    switch(player->direction)
    {
        case NORTH:
        position.y = player->position.y - 1;
        position.x = player->position.x;
        return position;
     

        case WEST:
        position.x = player->position.x - 1;
        position.y = player->position.y;
        return position;
      

        case SOUTH:
        position.y = player->position.y + 1;
        position.x = player->position.x;
        return position;
 

        case EAST:
        position.x = player->position.x + 1;
        position.y = player->position.y;
        return position;
  

        default:
        printf("INVALID INPUT.\n");
        break;

    }
    return position;
}



void updatePosition(Player * player, Position position)
{
    /**
     * Set the player's position to the provided position. Also increment the
     * moves count.
     */
    if(player != NULL)
    {
        player->position.x = position.x;    
        player->position.y = position.y;
        player->moves++;
    }
}

void displayDirection(Direction direction)
{
    /**
     * Prints the direction arrow to the console - based upon the direction set
     */
     
    if (direction == NORTH)
    {
        printf(DIRECTION_ARROW_OUTPUT_NORTH);
    }
    else if (direction == WEST)
    {
        printf(DIRECTION_ARROW_OUTPUT_WEST);
    }
    else if (direction == EAST)
    {
        printf(DIRECTION_ARROW_OUTPUT_EAST);
    }
    else
    {
        printf(DIRECTION_ARROW_OUTPUT_SOUTH);
    }
}
