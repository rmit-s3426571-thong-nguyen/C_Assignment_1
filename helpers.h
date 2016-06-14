#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

typedef enum boolean
{
    FALSE = 0,
    TRUE
} Boolean;

#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define DELIMS ", "


/**
 * This is used to compensate for the extra character spaces taken up by
 * the '\n' and '\0' when input is read through fgets().
 **/
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)
#define BUFFER_SIZE 80
#define EMPTY_STRING ""

/**
 * Call this function whenever you detect buffer overflow but only call this
 * function when this has happened.
 **/
void readRestOfLine();
Boolean is_int(const char * s);
void welcome_menu();
void playgame_menu();
void twoCommands_menu();
void threeCommands_menu();
void fourCommands_menu();
/*
void getInit(char *str, char **value1, int *value2, int *value3, char **value4);
*/
#endif
