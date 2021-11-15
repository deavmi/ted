#include<termios.h>
#include<stdint.h>

/**
 * @brief TedSession
 * 
 * Reppresents an editor session which is
 * the coupling of an open file open for
 * editing, an onscreen buffer, cursor position
 * data and more
 *
 * Sesions are chained toghether to form a link
 * list
 */
struct TedSession
{
    /* File being edited */
    uint32_t fd;

    /* Next session */
};
typedef struct TedSession TedSession;

/**
 * @brief TedScreen
 * 
 * This is what one sees finally on his screen
 * when using the editor. This houses position
 * of the TTY cursor relative to the sub-section
 * of the TTY that is used for the editor window
 */
struct TedScreen
{
    /* (x,y) position */
    uint32_t x;
    uint32_t y;

    /* Screen offset from top and right hand side */
    uint32_t minX;
    uint32_t minY;
    uint32_t maxX;
    uint32_t maxY;
};
typedef struct TedScreen TedScreen;

/**
 * @brief TedState
 * 
 * This is used to encapsulate all sub-state
 * objects into one that can be passed around
 * at a global level when all context it needed 
 */
struct TedState
{
    /* Old TTY state (for restoration on exit) */
    struct termios ttySettings;

    /* TTY device */
    uint32_t ttyFD;

    /* Screen */
    TedScreen* screen;

    /* Open Sessions */
    TedSession* sessions;
    
};
typedef struct TedState TedState;