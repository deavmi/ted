/**
 * @file editor.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdint.h>
#include<unistd.h>
#include "types.h"

void editorLoop(TedState* tState)
{
    uint8_t currentChar;
    /* TODO: Sanity check on sign of fd */
    while(1)
    {
        ssize_t count = read(tState->ttyFD, &currentChar, 1);

        /**
         * The TTY driver implements a non-blocking
         * read in the sense that if you read from it
         * and the TTY buffer is empty then it returns
         * immediately, so we need to do this
         */
        if(count > 0)
        {
            
            charInterp:

            printf("bruh: %d\n", currentChar);

            /* If Ctrl+X (24) */
            if(currentChar == 24)
            {
                break;
            }
            /* Backspace */
            else if(currentChar == 127)
            {

            }
            /* Control section */
            else if(currentChar == 27)
            {
                
                count = read(tState->ttyFD, &currentChar, 1);

                /* If it takes time for the sequence to come in */
                while(count < 0)
                {
                    /* TODO: Idk we might need to time it, what if */
                }

                
                /* TODO: We need to seek back if not recognizable */
                if(currentChar == 91)
                {

                }
                /* Push it back, not control sequence */
                else
                {
                    goto charInterp;
                }
            }
            else
            {
                write(tState->ttyFD, &currentChar, 1);
            }
        }


        
    }
    
}

void setCursorPosition(TedSession* tedSession, Coordinate newPos)
{
    /* Only set the cursor's position if it is still within range */
    if
    (
        tedSession->screen->min.x <= newPos.x &&
        tedSession->screen->min.y <= newPos.y &&
        tedSession->screen->max.x >= newPos.x &&
        tedSession->screen->max.y >= newPos.y
    )
    {
        /* Set the new position */
        tedSession->screen->cursor = newPos;
    }
}