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

#include "windows.h"
#include <iostream>
#include <fstream>

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



using namespace std;

#include <winsock.h> /* for socket(), bind(), and connect() */
#ifdef WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#pragma comment(lib, "Ws2_32.lib")


#else
// using gcc and minw
#include <unistd.h>     /* for close() */
#endif

//closesocket()

#include "IPTransportSock.h"

int GlobalError;

void IPTransportSock::DieWithError(char *errorMessage)
{
  GlobalError = WSAGetLastError();
  cout << errorMessage << "Error code: " << GlobalError << endl;
  
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
IPTransportSock::IPTransportSock()
: m_echo(0), m_hostName(0), m_remoteClientName(0), m_conntype(0), m_ipaddr(0), m_port(0), IPconnection()
{
   commonIPTransportSock();
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
IPTransportSock::IPTransportSock(int conntype, char * ipaddr, int port)
: m_echo(false), m_hostName(0), m_remoteClientName(0), m_conntype(conntype), m_ipaddr(ipaddr), m_port(port), IPconnection()
{
   commonIPTransportSock();

 
}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
IPTransportSock::IPTransportSock( IPconnectionConfig * config )
: m_echo(false), m_hostName(0), m_remoteClientName(0), IPconnection()
{
   commonIPTransportSock();

   if( config != 0)
   {

	 if( config->m_type == connectionConfig::TCPCONNECTION)
	 {
	   m_conntype = TCP_CONNECTION;

       m_port = config->m_Port; 

       m_ipaddr = config->m_IPaddress;

	 }
	 if( config->m_type == connectionConfig::UDPCONNECTION)
	 {
	   m_conntype = UDP_CONNECTION;

       m_port = config->m_Port; 

       m_ipaddr = config->m_IPaddress;

	 }
   }
}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::openConnection(void)
{
   static int status = 0;
   static bool alreadyConnected = false;
   
   unsigned int clntSock = 0; 
   
   if(alreadyConnected == false)
   {
     alreadyConnected = true;

     if( m_conntype == TCP_CONNECTION )
     {
      status = openTCPClient(&clntSock);

     }
     if( m_conntype == UDP_CONNECTION )
     {
      status = openUDPClient(&clntSock);

     }

   }
   return status;     
}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::connectToDevice()
{
   return connectToRemoteServer(m_ipaddr, m_port);
}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
void IPTransportSock::commonIPTransportSock(void)
{
	m_hostName = new char[16];
	m_remoteClientName = new char[16];	

        for(int x = 0; x < 16; x++)
        {
          m_hostName[x] = 0;
          m_remoteClientName[x] = 0;          	
        }
        
        GlobalError = 0;
        
}



/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
IPTransportSock::~IPTransportSock(void)    
{
  delete [] m_hostName;
  delete [] m_remoteClientName;
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::openTCPServer(unsigned short servPort) 
{

    int retval = SUCCESSFUL_RETURN;

    m_serverPort = servPort;  /* First arg:  local port */    

#ifdef _WIN32

    // The highest version of Windows Sockets specification that the caller can use. 
    // The high-order byte specifies the minor version number; the low-order byte specifies the major version number.    
    WORD wVersionRequested; // WORD is unsigned short

    WSAData wsaData;

    // A pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation.    
    LPWSADATA lpWSAData = &wsaData; // same as pointer to WSAData structure
            
    wVersionRequested = MAKEWORD(2,2); // version 2.2 is the latest winsock

    // Initialize WinSock and check the version
    if (WSAStartup( wVersionRequested, &wsaData) != 0)
    {	
	DieWithError("WSAStartup() failed");
    }

#endif    
    
    /* Create socket for incoming connections */
    if ((servSock = (unsigned int)socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        DieWithError("socket() failed");
    } 
    /* Construct local address structure */
    memset(&serverAddr, 0, sizeof(serverAddr));   /* Zero out structure */
    serverAddr.sin_family = AF_INET;                /* Internet address family */
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    serverAddr.sin_port = htons(m_serverPort);      /* Local port */

    /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
    {
	DieWithError("bind() failed");
    }


    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0)
    {
        DieWithError("listen() failed");
    }
    else
    {
	    cout << "listening for connection on server port: " << servPort; 
	    cout << endl;   
    }

    return retval;
    
}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::openUDPServer(unsigned short servPort)
{
	// code to be done...

    int retval = -1;

    m_serverPort = servPort;  /* First arg:  local port */    

    return retval;   
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::openTCPClient(unsigned int * clntSock)
{
   int retval = SUCCESSFUL_RETURN;

#ifdef _WIN32

    // The highest version of Windows Sockets specification that the caller can use. 
    // The high-order byte specifies the minor version number; the low-order byte specifies the major version number.    
    WORD wVersionRequested; // WORD is unsigned short

    WSAData wsaData;

    // A pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation.    
    LPWSADATA lpWSAData = &wsaData; // same as pointer to WSAData structure
            
    wVersionRequested = MAKEWORD(2,2); // version 2.2 is the latest winsock

    // Initialize WinSock and check the version
    if (WSAStartup( wVersionRequested, &wsaData) != 0)
    {	
	DieWithError("WSAStartup() failed");
    }

#endif    
    
    /* Create socket for connecting client to a remote server */
    if ((m_clientSock = (unsigned int)socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        DieWithError("socket() failed");
        retval = FAILED_RETURN;
    }
    else
    {
      *clntSock = m_clientSock;
    } 
    
    return retval;
}
/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::openUDPClient(unsigned int * clntSock)
{
   int retval = SUCCESSFUL_RETURN;

#ifdef _WIN32

    // The highest version of Windows Sockets specification that the caller can use. 
    // The high-order byte specifies the minor version number; the low-order byte specifies the major version number.    
    WORD wVersionRequested; // WORD is unsigned short

    WSAData wsaData;

    // A pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation.    
    LPWSADATA lpWSAData = &wsaData; // same as pointer to WSAData structure
            
    wVersionRequested = MAKEWORD(2,2); // version 2.2 is the latest winsock

    // Initialize WinSock and check the version
    if (WSAStartup( wVersionRequested, &wsaData) != 0)
    {	
	DieWithError("WSAStartup() failed");
    }

#endif    
    
    /* Create socket for connecting client to a remote server */
    if ((m_clientSock = (unsigned int)socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        DieWithError("socket() failed");
        retval = FAILED_RETURN;
    }
    else
    {
      *clntSock = m_clientSock;
    } 
    
    return retval;
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::connectToRemoteServer(char * servIP, unsigned short servPort)
{
	int status = 0;

    m_serverPort = servPort;  /* First arg:  local port */    
        
   // Construct the server address structure 
    memset(&m_remoteServerAddr, 0, sizeof(m_remoteServerAddr));     // Zero out structure 
    m_remoteServerAddr.sin_family      = AF_INET;             // Internet address family 
    m_remoteServerAddr.sin_addr.s_addr = inet_addr(servIP);   // Server IP address 
    m_remoteServerAddr.sin_port        = htons(m_serverPort); // Server port 
  
	if( m_conntype == TCP_CONNECTION )
    {
      // Establish the connection to the echo server 
      if (connect(m_clientSock, (struct sockaddr *) &m_remoteServerAddr, sizeof(m_remoteServerAddr)) < 0)
	  {
		DieWithError("connect() to remote server failed");
		status = 1;
	  }

	}

	return status;
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::listenForConnection(unsigned int * clntSock, int blocking)
{
	// find out how to undo this action
    //if(blocking == 0) fcntl(servSock,F_SETFL,0_NONBLOCK | FASYNC)
    
    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        m_remoteClientAddrStructLen = sizeof(remoteClientAddr);

        /* Wait for a client to connect and save the client socket handle in user supplied pointer */
        if ((*clntSock = (unsigned int)accept(servSock, (struct sockaddr *) &remoteClientAddr, &m_remoteClientAddrStructLen)) < 0)
        {                      
            DieWithError("accept() failed");
			return 1;
        }
        else
        {
          break;
        }      
        
    }
    
    return 0;
}



/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::waitForRxMessage(unsigned int socket, int *recvMsgSize, unsigned char * rxbuf = 0, int rxbufsize = 0)
{
      int i;
      int exit = 0;
      int retval = SUCCESSFUL_RETURN;
         
      for(i = 0; i < RCVBUFSIZE; i++) m_rxBuffer[i] = 0; // clear buffer each pass
      
      if(rxbuf != 0) 
      {
        for(i = 0; i < rxbufsize; i++){rxbuf[i] = 0;}
      }

      /* Receive message from client */
      if ((*recvMsgSize = recv(socket, m_rxBuffer, RCVBUFSIZE, 0)) < 0)
      {
        DieWithError("recv() failed");
      }

      
      if(recvMsgSize > 0)
      {
 
         // copy message     
         for(i = 0; i < *recvMsgSize; i++)
         {
           if(i < rxbufsize) // be sure not to overflow dest buffer
           {
             rxbuf[i] = m_rxBuffer[i]; // make a copy for the caller
           }
         }
      }
       


    /* zero indicates end of transmission */    
    if( *recvMsgSize == 0)
    {
    	 retval = FAILED_RETURN;
    }
    else
    {
      if(m_echo)
      {
          /* Echo message back */
          sendMessage(socket,m_rxBuffer, *recvMsgSize);       	
      }	
    }
    

    return retval;    
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::receiveData(unsigned char * buffer, int lenBuf, int * lenReceived)
{    
	return waitForRxMessage(m_clientSock, lenReceived, buffer, lenBuf);
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
char * IPTransportSock::getRemoteClientIPAddress(void)
{
  return inet_ntoa(remoteClientAddr.sin_addr);
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
char * IPTransportSock::getServerMachineName(void)
{
  gethostname(m_hostName,16); // 16 is buffersize	
  return m_hostName;
  
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
char * IPTransportSock::getRemoteClientMachineName(int clntSock)
{
    struct hostent * hp;
    size_t namelength;
	
    hp = gethostbyaddr( (char *)&remoteClientAddr.sin_addr.s_addr,    sizeof(remoteClientAddr.sin_addr.s_addr),AF_INET  );                    
    
    namelength = (int)strlen(hp->h_name);
    	
    for(unsigned int x = 0; x < namelength; x++ )
    {
    	 m_remoteClientName[x] = *(((char *)(hp->h_name)) + x);
    }
    	
  return m_remoteClientName;
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::close(unsigned int socket)
{
     int retval = SUCCESSFUL_RETURN;
     

     
#ifdef _WIN32
     closesocket(socket);
     WSACleanup();  // Cleanup Winsock        
#else
     close(socket);    /* Close client socket */
#endif
     return retval; 
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::closeConnection(void)
{
   return close(m_clientSock);
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::sendMessage(unsigned int socket, char * txmsg, int txmsgsize)
{
     
   if(send(socket, txmsg, txmsgsize, 0) != txmsgsize)
	{
		DieWithError("connect() to remote server failed");
		return 1;
	}
	else
	{
		return 0;
	}
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::sendData( char * buffer, int len)
{
  int status = sendMessage(m_clientSock, buffer, len);
  return status;

}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
int IPTransportSock::sendData( char c)
{
  char ch = c;
  return sendMessage(m_clientSock, &ch, 1);
}

/*************************************************************************
*
*   METHOD NAME:
*
*   PARENT CLASS:   
*
*---------------------------------- PURPOSE ------------------------------
* 
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   PARAMETERS:           
*                      
*
*   RETURN VALUE:     
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*    
*  
*  .
*************************************************************************/
connection::connectionStatus_t IPTransportSock::getStatus(connection::connectionStatusType_t type)
{
	connection::connectionStatus_t retval = m_connectionStatus;
	int selectResult;
  
   //struct timeval
   //{
     //time_t tv_sec;
     //time_t tv_usecs; 
   //}
    int maxDescriptor = m_clientSock;
	fd_set sockSet;
	struct timeval selTimeout;
	selTimeout.tv_sec = 0;
	selTimeout.tv_usec = 250000; // set to 250 milli seconds (subjective choice)

	if( m_clientSock > maxDescriptor){ maxDescriptor = m_clientSock; }
	FD_ZERO(&sockSet);


	switch( type)
	{
	case connection::CONNECTION_INITSTATUS:
            retval = connection::CONNECTION_INITIALIZED;
		break;

	    case connection::CONNECTION_TXSTATUS:


            //select int maxDescPlus1, fd_set * readDescs, fd_set * writeDesc, fd_set exceptionDescs, &timeout                     
            selectResult = select(maxDescriptor + 1, NULL, &sockSet, NULL, &selTimeout);
            if(selectResult == 0)  // nothing ready and timeout expired
			{
              retval = connection::CONNECTION_TXBUSY;
			}
			else if(selectResult == 1) // ready
			{
              retval = connection::CONNECTION_TXREADY;
			}
			else if(selectResult == -1) // error
			{
              retval = connection::CONNECTION_ERR;
			}


		break;

	    case connection::CONNECTION_RXSTATUS:

            //select int maxDescPlus1, fd_set * readDescs, fd_set * writeDesc, fd_set exceptionDescs, &timeout                     
            selectResult = select(maxDescriptor + 1, &sockSet, NULL, NULL, &selTimeout);
            if(selectResult == 0)  // nothing ready and timeout expired
			{
              retval = connection::CONNECTION_RXNODATA;
			}
			else if(selectResult == 1) // ready
			{
              retval = connection::CONNECTION_RXHASDATA;
			}
			else if(selectResult == -1) // error
			{
              retval = connection::CONNECTION_ERR;
			}

		break;
	}


 
	return retval;  
}


