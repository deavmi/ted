/**
* Ted
*
* Extensible text editor and lightweight
*/

#include<stdint.h>
#include "types.h"

// extern void setTerm();

/**
 * Define prototypes to satisfy compiler
 * (will be used to link)
 */
void setTerm(TedState* tState);
void editorLoop(TedState* tState);
void saveTTYState(TedState* tState);
void restoreTTYState(TedState* tState);

/**
 * Global data
 */
TedState tState;

int32_t main()
{
    /* TODO: Sanity check on FD 0 (check type and is open) */
    tState.ttyFD = 0;

    /**
     * Save current TTY configuration for
     * Restoration later (on exit)
     */

    saveTTYState(&tState);

    /**
     * @brief Configure the TTY for RAW-esque
     * operation
     */
    setTerm(&tState);



    /* Start the editor loop with the fd 0 */
    editorLoop(&tState);

    /* Restore the TTY to its state before Ted started */
    restoreTTYState(&tState);

    return 0;
}