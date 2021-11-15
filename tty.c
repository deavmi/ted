/**
 * @file tty.c
 * @author Tristan B. Kildaire (deavmi@redxen.eu)
 * @brief TTY management routines
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdint.h>
#include<termios.h>
#include<sys/ioctl.h>
#include "types.h"

void setTerm(struct TedState* tState)
{
    struct termios ttySettings;

    /* Zero out bit flags for input settings */
    ttySettings.c_cflag = 0;

    /* Ignore breaks, so go raw effectively */
    ttySettings.c_cflag |= IGNBRK;

    ttySettings.c_lflag = 0;
    // ttySettings.c_lflag = ECHO;

    ttySettings.c_cc[VMIN] = 1;  // read one byte at a time
    ttySettings.c_cc[VTIME] = 0; // no time limit for read

    int32_t status = tcsetattr(tState->ttyFD, 0, &ttySettings);
}

void saveTTYState(struct TedState* tState)
{
    /* Fetch current TTY configuration */
    struct termios ttySettings;
    tcgetattr(tState->ttyFD, &ttySettings);

    /* Save current TTY configuration */
    tState->ttySettings = ttySettings;
}

void restoreTTYState(struct TedState* tState)
{
    /* Restore the TTY to the saved state */
    tcsetattr(tState->ttyFD, 0, &tState->ttySettings);
}
