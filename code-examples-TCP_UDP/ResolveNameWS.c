/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */

#include <stdio.h>      /* for fprintf() */
#include <winsock.h>    /* for gethostbyname() */

unsigned long ResolveName(char name[])
{
    struct hostent *host;            /* Structure containing host information */

    if ((host = gethostbyname(name)) == NULL)
    {
        fprintf(stderr, "gethostbyname() failed");
        exit(1);
    }

    /* return the binary, network byte ordered address */
    return *((unsigned long *) host->h_addr_list[0]);
}
