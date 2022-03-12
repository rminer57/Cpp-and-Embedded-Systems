/*******************************************************************************
*
*                         C++  IMPLEMENTATION  F I L E
*
*            COPYRIGHT 2011 MOTOROLA, INC. ALL RIGHTS RESERVED.
*                    MOTOROLA CONFIDENTIAL PROPRIETARY
*
********************************************************************************
*
*   FILE NAME      : 
*
*-------------------------------- PURPOSE --------------------------------------
*
*  
*
*--------------------------- DEPENDENCY COMMENTS -------------------------------
*
* 
*------------------------------- REVISIONS -------------------------------------
*
* Date        Name      Description
* ----------  --------  --------------------------------------------
* 12/29/2010 R.Miner    Initial Creation
* 

*******************************************************************************/
#ifndef IPTransportSock_H
#define IPTransportSock_H

//---------------------------- HEADER FILE INCLUDES ----------------------------
#include <winsock.h>    /* for socket(),... */
#include "Common.h"

//-------------------------------- CONSTANTS -----------------------------------

#ifndef SUCCESSFUL_RETURN
#define SUCCESSFUL_RETURN 0
#endif

#ifndef FAILED_RETURN
#define FAILED_RETURN -1
#endif

#define MAXPENDING 5    /* Maximum outstanding connection requests */    
#define RCVBUFSIZE 100   /* Size of receive buffer */

#define UDP_CONNECTION 1
#define TCP_CONNECTION 2    

/*************************************************************************
*
*   CLASS NAME:
*
*   RELATIONSHIPS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PUBLIC METHODS AND ATTRIBUTES:           
*                      
*   
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/


class IPTransportSock : public IPconnection
{
public:

   /*******************************************************************************
    *
    *   This is the class constructor.
    *   TCP and UDP are currently supported.
    *   
    *
    *******************************************************************************/
    IPTransportSock();  
    IPTransportSock(int conntype, char * ipaddr, int port);
    IPTransportSock( IPconnectionConfig * config );
    void commonIPTransportSock(void);
     
   /*******************************************************************************
    *
    *   This is the IPTransportSock class destructor.
    *
    *******************************************************************************/
    virtual ~IPTransportSock(void);
    
   /*******************************************************************************
    *
    *   
    * starts a server and listens for a tcp connection on the local machine
    *******************************************************************************/
    int openTCPServer(unsigned short servPort);
    int openTCPClient(unsigned int * clntSock);

    int openUDPServer(unsigned short servPort);
    int openUDPClient(unsigned int * clntSock);   
   /*******************************************************************************
    *
    *   
    *
    *******************************************************************************/
    int connectToRemoteServer(char * servIP, unsigned short servPort);

    int waitForRxMessage(unsigned int socket, int *recvMsgSize, unsigned char * rxbuf, int rxbufsize);  // server and client
    int sendMessage(unsigned int socket, char * txmsg, int txmsgsize);                         // server and client
    int listenForConnection(unsigned int * clntSock, int blocking = 1);                        // server only    
    
    void DieWithError(char *errorMessage);
    
    char * getRemoteClientIPAddress(void);
    
    char * getServerMachineName(void);
    char * getRemoteClientMachineName(int clntSock);     
    
    int close(unsigned int socket);

 
    virtual int connectToDevice();


	// connection interfaces...
    virtual int openConnection();
    virtual int closeConnection(void);
    virtual int sendData( char * buffer, int len);
    virtual int sendData( char c);
    virtual int receiveData(unsigned char * buffer, int lenBuf, int * lenReceived);
    virtual connectionStatus_t getStatus(connection::connectionStatusType_t type);
           
private:

    // used for constructing a server
    char m_rxBuffer[RCVBUFSIZE];        /* Buffer for echo string */
    unsigned int servSock;              /* Socket descriptor for server */
    struct sockaddr_in serverAddr;      /* Local address */ 
    unsigned short m_serverPort;        /* Server port */
    int m_remoteClientAddrStructLen;    /* Length of remote client address data structure */
    char * m_hostName;
    char * m_remoteClientName;
    
    // initialized by IPTransportSock(int conntype, char * ipaddr, int port)
    int m_conntype; 
    char * m_ipaddr; 
    int m_port; 
    int m_echo;
           
    // used for constructing a client
    struct sockaddr_in remoteClientAddr;   /* remote lient address */ 
    unsigned int m_clientSock;             /* Socket descriptor for opening a client */      
    struct sockaddr_in m_remoteServerAddr; // remote server address     
};
#endif