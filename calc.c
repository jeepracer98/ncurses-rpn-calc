#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

// 2 1: stack_1
// 1 debug_line
// 0 input_line

int const MAX_NUM_LENGTH = 20;
int stackSize;
int const 

int pushToStack(char numToAdd[MAX_NUM_LENGTH], char* stack[MAX_NUM_LENGTH], int stackSize)
{
    ++stackSize;
    // TODO
}


int main()
{
    stackSize = 0; // initialize global stackSize

    WINDOW* mainWindow;

    // init the screen
    if ( (mainWindow = initscr()) == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }

    int w = getmaxx(mainWindow);
    int h = getmaxy(mainWindow);

    // A character to store the getchar() each time around    
    char c;

    // A string to store the string representing the currently edited number
    char currNumStr[MAX_NUM_LENGTH + 1];
    int i;
    for (i = 0; i < MAX_NUM_LENGTH + 1; ++i)
    {
        currNumStr[i] = 0;
    }

    while (1)
    {

        mvprintw(h - 2, 0, "%d", strlen(currNumStr));
        mvprintw(h - 2, 5, "%d", c);
        mvprintw(h - 1, 0, currNumStr);
        mvprintw(10, 10, "hello world");
        
        refresh();
        wclear(mainWindow);

        c = getchar();
        if (c == 'q')
        {
            break;
        }
        
        else if (c >= 48 && c <= 56) // decimal number
        {
            if (strlen(currNumStr) < MAX_NUM_LENGTH - 1)
            {
                strncat(currNumStr, &c, 1);
            }
        }
        else if (c == 10 || c == 127) // backspace
        {
            currNumStr[strlen(currNumStr) - 1] = 0;
        }
        else if (c == 13) // enter
        {
            // TODO: move other numbers in array
            mpf_init_set_str(/* TODO[0] */, currNumStr, 10);
        }
    }


    delwin(mainWindow);
    endwin();
    refresh();

    return 0;
}
