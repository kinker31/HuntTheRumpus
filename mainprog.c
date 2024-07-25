#include "mainlib.h"

int main()
{
    initscr(); noecho();
    printw("Welcome to Hunt the Rumpus!\n"); refresh();
    sleep(1);
    char selection;
    unsigned short int options;
    while(selection != 'q')
    {
        clear();
        printw("Make a selection, or press h for help: ");
        refresh();
        selection = getch();
        printw("%c\n", selection);
        switch(selection)
        {
            case 'h':
                PrintCommands();
                break;
            case 'q':
                printw("Well, it's been fun, see you next time!\n"); refresh();
                sleep(1);
            default:
                break;
        }
    }
    endwin();
    return 0;
}