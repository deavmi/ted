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
            write(tState->ttyFD, &currentChar, 1);
            // printf("%d\n", currentChar);

            /* If Ctrl+X (24) */
            if(currentChar == 24)
            {
                break;
            }
        }


        
    }
    
}