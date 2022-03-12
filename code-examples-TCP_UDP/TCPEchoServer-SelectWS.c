/* CHANGES FROM UNIX VERSION                                                   */
/*                                                                             */
/* 1.  Changed header files.                                                   */
/* 2.  Added WSAStartUP() and WSACleanUp().                                    */
/* 3.  Used closesocket() instead of close().                                  */
/* 3.  Since socket descriptors are NOT file descriptors in Winsock, we cannot */
/*     use select to detect input from the keyboard; therefore, this version   */
/*     of the program does not allow user input (hitting return) for program   */
/*     termination.                                                            */
/* 4.  Under Winsock, the first argument to select (maximum file descriptor)   */
/*     is ignored.                                                             */

#include "TCPEchoServerWS.h"   /* TCP echo server includes */

void main(int argc, char *argv[])
{
    int *servSock;                   /* Socket descriptors for server */
    fd_set sockSet;                  /* Set of socket descriptors for select() */
    long timeout;                    /* Timeout value given on command-line */
    struct timeval selTimeout;       /* Timeout for select() */
    int running = 1;                 /* 1 if server should be running; 0 otherwise */
    int noPorts;                     /* Number of port specified on command-line */
    int port;                        /* Looping variable for ports */
    unsigned short portNo;           /* Actual port number */
    WSADATA wsaData;                 /* Structure for WinSock setup communication */

    if (argc < 3)     /* Test for correct number of arguments */
    {
        fprintf(stderr, "Usage:  %s <Timeout (secs.)> <Server Port 1> ...\n", argv[0]);
        exit(1);
    }

    timeout = atol(argv[1]);        /* first arg: Timeout */
    noPorts = argc - 2;             /* Number of ports is argument count minus 2 */

    /* Allocate list of sockets for incoming connections */
    servSock = (int *) malloc(noPorts * sizeof(int));

    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) /* Load Winsock 2.0 DLL */
    {
        fprintf(stderr, "WSAStartup() failed");
        exit(1);
    }

    /* Create list of ports and sockets to handle ports */
    for (port = 0; port < noPorts; port++)
    {
        /* Add port to port list */
        portNo = atoi(argv[port + 2]);  /* Skip first two arguments */

        /* Create port socket */
        servSock[port] = CreateTCPServerSocket(portNo);
    }

    while (running)
    {
        /* Zero socket descriptor vector and set for server sockets */
        /* This must be reset every time select() is called */
        FD_ZERO(&sockSet);
        for (port = 0; port < noPorts; port++)
            FD_SET(servSock[port], &sockSet);

        /* Timeout specification */
        /* This must be reset every time select() is called */
        selTimeout.tv_sec = timeout;       /* timeout (secs.) */
        selTimeout.tv_usec = 0;            /* 0 microseconds */

        /* Suspend program until descriptor is ready or timeout */
        /* The first parameter to select() is ignored in Winsock */
        if (select(0, &sockSet, NULL, NULL, &selTimeout) == 0)
            printf("No echo requests for %ld secs...Server still alive\n", timeout);
        else 
        {
            for (port = 0; port < noPorts; port++)
                if (FD_ISSET(servSock[port], &sockSet))
                {
                    printf("Request on port %d (cmd-line position):  ", port);
                    HandleTCPClient(AcceptTCPConnection(servSock[port]));
                }
        }
    }

    /* Close sockets */
    for (port = 0; port < noPorts; port++)
        closesocket(servSock[port]);

    /* Free list of sockets */
    free(servSock);

    WSACleanup();  /* Cleanup Winsock */

    exit(0);
}
