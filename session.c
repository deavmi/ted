/**
 * @file session.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdint.h>
#include "types.h"
#include<stdlib.h>

/**
 * @brief Opens up a new session for the given
 * file pointed to by fd
 * 
 * @param fd file to open an editor session for
 * @return TedSession* the newly opened session
 */
TedSession* newSession(uint32_t fd)
{
    /* TODO: Sanity check on fd */

    TedSession* tedSession = malloc(sizeof(TedSession));

    /**
     * @brief On allocation success
     * setup all further fields of
     * the allocated data structure
     */
    if(tedSession)
    {
        /* Set the fd to edit */
        tedSession->fd = fd;

        /* TODO: Setup further things here */
    }

    return tedSession;
}