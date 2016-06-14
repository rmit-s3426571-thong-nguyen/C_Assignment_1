#include "carboard.h"

int main()
{
    char selection [1 + 2];
    int checked = FALSE;
    do
    {
    	welcome_menu();
    	do
    	{
    		fgets(selection,1 + 2,stdin);
    		if(selection[strlen(selection) - 1] != '\n')
    		{
    			printf("Please enter a number:)\n");
    			readRestOfLine();
    		}
    		else
    		{
    			selection[strlen(selection) -1] = '\0';
    			checked = TRUE;
    		}
    	} while(!checked);
    	switch(*selection)
    	{
    		case '1':
    			playGame();
    			break;
    		case '2':
    			showStudentInformation();
    			break;
    		case '3':
    			printf("Good bye!:) \n\n");
    			exit(0);
    			break;
    		default: 
            printf("********  Please enter a correct selection  ********.\n");
            printf("***** There are 3 options such as 1,2 and 3 :) *****\n");
    	}

    } while (*selection != '3' && checked);
    return EXIT_SUCCESS;
}

void showStudentInformation()
{
    printf("-------------------------------------------\n");
    printf("Student Name : %s\n",STUDENT_NAME);
    printf("Student ID : %s\n",STUDENT_ID);
    printf("Student Email :%s\n",STUDENT_EMAIL);
    printf("--------------------------------------------\n");
}
