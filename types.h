#include<termios.h>
#include<stdint.h>

/**
 * @brief Coordinate
 * 
 * Just plain old (x,y) coordinates
 */
struct Coordinate
{
    uint32_t x;
    uint32_t y;
};
typedef struct Coordinate Coordinate;


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
    Coordinate cursor;

    /* Screen offset from top and right hand side */
    Coordinate min;
    Coordinate max;
};
typedef struct TedScreen TedScreen;

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

    /* Screen */
    TedScreen* screen;

    /* Next session */
};
typedef struct TedSession TedSession;

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

    /* Open Sessions */
    TedSession* sessions;
    
};
typedef struct TedState TedState;