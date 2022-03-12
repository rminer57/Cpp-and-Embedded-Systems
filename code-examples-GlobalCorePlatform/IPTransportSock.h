
#ifndef IPTransportSock_H
/*******************************************************************************
*
*                   H E A D E R   S P E C I F I C A T I O N
*
*                      Copyright Motorola, Inc. 2010
*                    MOTOROLA CONFIDENTIAL PROPRIETARY
*                        Template Version: R02.02
*
********************************************************************************
*
*   FILE NAME      : IPTransportSock.h
*   ORIGINATOR     : Randy Miner
*   DATE OF ORIGIN : 9 Oct. 2010
*
*******************************************************************************/
#define IPTransportSock_H

//---------------------------- HEADER FILE INCLUDES ----------------------------
#include <winsock2.h>
#include "Common.h"
#include "connections.h"

//-------------------------------- CONSTANTS -----------------------------------

// same as PASS = 1 and FAIL = 0 in atlas common.h
#ifndef SUCCESSFUL_RETURN
#define SUCCESSFUL_RETURN 1
#endif

#ifndef FAILED_RETURN
#define FAILED_RETURN 0
#endif

#define MAXPENDING 5    /* Maximum outstanding connection requests */    
#define RCVBUFSIZE 2500   /* Size of receive buffer */

#define HOSTCLIENTNAMEARRAYSZ 64

#define UDP_CONNECTION 1
#define TCP_CONNECTION 2

typedef enum connType_t
{
  UDP_CONN = 1,
  TCP_CONN = 2
}; 

//------------------------------- ENUMERATIONS ---------------------------------
//----------------------------- BASIC DATA TYPES -------------------------------
//------------------------ STRUCTURE/UNION DATA TYPES --------------------------
//------------------------------ CLASS DEFINITION ------------------------------

class IPTransportSock : public IPconnection
{
public:

   /*******************************************************************************
    *
    *   This is the class constructor.
    *
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

    virtual int openConnection();
    virtual int closeConnection(void);
    virtual int sendData( char * buffer, int len);
    virtual int sendData( char c);
    virtual int receiveData(char * buffer, int lenBuf, int * lenReceived);
    virtual int connectToDevice();
    
         
                            
private:

    // used for constructing a server
    char m_rxBuffer[RCVBUFSIZE];        /* Buffer for echo string */
    unsigned int servSock;              /* Socket descriptor for server */
    struct sockaddr_in serverAddr;      /* Local address */ 
    unsigned short m_serverPort;        /* Server port */
    int m_remoteClientAddrStructLen;    /* Length of remote client address data structure */
    char * m_hostName;
    char * m_remoteClientName;
               
    // used for constructing a client
    struct sockaddr_in remoteClientAddr;   /* remote lient address */ 
    unsigned int m_clientSock;             /* Socket descriptor for opening a client */      
    struct sockaddr_in m_remoteServerAddr; // remote server address     
};

#define NETWRKCONNECTIONS_MAX 32
class NetwrkManager
{
public:

NetwrkManager();
~NetwrkManager();

// connType_t  int UDP_CONN = 1, int TCP_CONN = 2 
int open( unsigned int * connhandle, connType_t connType);
int close( unsigned int * connhandle);
int setParams( unsigned int * connhandle, AtlasString & newparams);
int getParams( unsigned int * connhandle, AtlasString & curparams);
int connect( unsigned int * connhandle, char * servIP, unsigned short servPort);
int listenForConnection( int * connhandle);
int disconnect( unsigned int * connhandle);
int send( unsigned int * connhandle, AtlasString & txdata);
int send( unsigned int * connhandle, char * rxarray, int lenrecvd);
int send( unsigned int * connhandle, char c);
int send( unsigned int * connhandle, int txval);
int send( unsigned int * connhandle, double & txval);

int recv( unsigned int * connhandle, AtlasString & rxdata);
int recv( unsigned int * connhandle, char * txarray, int txarraylen);
int recv( unsigned int * connhandle, char * c);
int recv( unsigned int * connhandle, int & rxval);
int recv( unsigned int * connhandle, double & rxval);
bool isDataAvail( int * connhandle);

// add serialize and deserialize

protected:

static IPTransportSock ** m_connectionArray; 

private:

};



#endif


