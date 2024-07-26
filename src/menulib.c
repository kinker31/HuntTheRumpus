#include "menulib.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ncurses.h>
#include <fcntl.h>
#include <linux/stat.h>
#include <sys/stat.h>

/*
Game options are to be stored as an unsigned short int, saved to ~/.config/HuntTheRumps as a small binary file, something like that.
From MSB to LSB, presuming 1 enables and 0 disables:
1. Spawns more rumpuses, with slightly more ammo to compensate per rumpus spawned.
2. Lets you use Dennis the Lifeline.
3. Walls generate in more places than the borders.
4. 1 makes pits an insta-kill, 0 lets you tumble down them up to three times.
5. Faulty teleporters are able to spawn.
6. Ammo-carrying corpses are able to spawn.
7. Rumpuses have a chance to move after a player moves.
8. Rumpuses avoid pits.
16. Prints the maze per turn, slightly cheat-y.
*/

void InitDirectory()
{
    DIR* cfgDir = opendir("~/.config/HuntTheRumpus");
    if(cfgDir == NULL)
    {
        int createDir = mkdir("~/.config/HuntTheRumpus", S_IRWXU);
    }
    closedir(cfgDir);
}

void PrintCommands()
{
    printw("[H]elp: Prints this screen.\n");
    printw("[O]ptions: Opens up the options, which has a menu of it's own.\n");
    printw("[N]ew Game: \n");
    printw("[C]ustom Maze: \n");
    printw("Please use lowercase keys when selecting, and this menu might change in the future!\n");
    printw("Press any key to continue.\n"); refresh();
    char dummyValue = getch();
}

void SaveOptions(unsigned short int *op)
{
    FILE* cfgFile = fopen("~/.config/HuntTheRumpus/config.rumpus", 'w');
    if(cfgFile != NULL)
    { int write = putc(*op, cfgFile); }
    fclose(cfgFile);
}

void LoadOptions(unsigned short int *op)
{
    FILE* cfgFile = fopen("~/.config/HuntTheRumpus/config.rumpus", 'r');
    if(cfgFile != NULL)
    { *op = getw(cfgFile); }
    fclose(cfgFile);
}

void GetOpState(unsigned short int *op, unsigned short int pick, char *str)
{
    unsigned short int tempInt = (1 << pick) & *op;
    bool state = (tempInt > 0);
    if(state) {strcpy(str, "on."); return;}
    strcpy(str, "off");
}

void PrintOptions()
{
    printw("HOW TO OPTIONS:\n");
    printw("[H]elp: Prints this screen.\n");
    printw("[=], or rather, +: Picks the next option.\n");
    printw("[-], minus: Picks the previous option.\n");
    printw("[T]oggle: Toggles the selected option between on or off.\n");
    printw("[S]ave: Writes the toggled options to a file.\n");
    printw("[L]oad: Loads options from a file to the program.\n");
    printw("[Q]uit: Exits the options menu.\n\n");
    printw("AVAILABLE OPTIONS:\n");
    printw("(Put options here later.)\n\n");
    printw("Please use lowercase keys when selecting, and this menu might change in the future!\n");
    printw("Press any key to continue.\n"); refresh();
    char dummyValue = getch();
}

void OptionsScreen(unsigned short int *op)
{
    unsigned short int picker;
    char opChar = 'n'; char stateStr[4];
    clear();
    printw("Welcome to the Options Menu!\n"); refresh();
    sleep(1);
    while(opChar != 'q')
    {
        clear();
        GetOpState(op, picker, stateStr);
        printw("Option %hu is %s\n", picker, stateStr); refresh();
        opChar = getch();
        switch(opChar)
        {
            case 'h':
                PrintOptions();
                break;
            case '=':
                if(picker < 16) {picker++;}
                break;
            case '-':
                if(picker > 0) {picker--;}
                break;
            case 't':
                ToggleOption(picker, op);
                break;
            case 's':
                SaveOptions(op);
                break;
            case 'l':
                LoadOptions(op);
                break;
            case 'q':
                printw("Returning to the main menu...\n"); refresh();
                sleep(1);
                break;
        }
    }
}

void PrintGameCommands()
{
    printw("[N]orth, [E]ast, [W]est, and [S]outh: Moves you one tile in the respective direction, if valid.\n");
    printw("Rumpis [G]un: Primes the Rumpus gun, the same four directions used to fire the thing.\n Make sure you hit a Rumpus.\n");
    printw("[D]ennis: Summons forth the auditory help of Dennis, who'll give you a hint on where the Rumpus is.\n");
    printw("[H]elp: Prints this screen.\n");
    printw("[Q]uit: Makes you instantly die, quitting the game.\n");
    printw("Please use lowercase keys when selecting, and this menu might change in the future!\n");
    printw("Press any key to continue.\n"); refresh();
    char dummyValue = getch();
}
