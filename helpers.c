#include "helpers.h"

void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n');
    /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}
/* check whether it is an int or not. */
Boolean is_int(const char * s)
{
    while(*s)
    {
        if(!isdigit(*s))
            return FALSE;
        ++s;
    }
    return TRUE;
}

void welcome_menu()
{
     printf("\nWelcome to Car Board\n");
     printf("--------------------\n");
     printf("1.Play game.\n");
     printf("2.Show student's information\n");
     printf("3.Quit\n\n");
     printf("Please enter your choice: \n\n");
}

void playgame_menu()
{
    printf("You can use the following commands to play the game:\n");
    printf("load <g>\n");
    printf("    g: number of the game board to load.\n");
    printf("init <x>,<y>,<direction>\n");
    printf("    x: horizontal position of the car on the board (between 0 & 9)\n");
    printf("    y: vertical position of the car on the board (between 0 & 9)\n");
    printf("    direction: direction of the car's movement (north, east, south, west\n");
    printf("forward (or f)\n");
    printf("turn_left (or l)\n");    
    printf("turn_right (or r)\n");
    printf("quit\n\n");
}

void twoCommands_menu()
{
    printf("At this stage of the program, only two commands are acceptable: \n");
    printf("load <g>\n");
    printf("quit\n\n");
}
void threeCommands_menu()
{
    printf("At this stage of the program, only three commands are acceptable: \n");
    printf("load <g>\n");
    printf("init <x>,<y>,<direction>\n");
    printf("quit\n\n");
}
void fourCommands_menu()
{
    printf("At this stage of the program, only four commands are acceptable:\n");
    printf("forward (or f)\n"); 
    printf("turn_left (or l)\n"); 
    printf("turn_right (or r)\n"); 
    printf("quit\n\n"); 
}



